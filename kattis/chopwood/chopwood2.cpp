#define INF 0x3f3f3f3f
#define pb(x) push_back(x)
#define sz(x) (int)(x).size()
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll, ll> pii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vi> vii;
typedef vector<vector<ii>> viii;

vector< ii > prufer(vi const& code){
  int n = code.size() + 2;
  vi deg(n+1, 1);
  for (int i : code)
    deg[i]++;
  int ptr = 1;
  while (deg[ptr] != 1)
    ptr++;
  int leaf = ptr;

  vector<ii> edges;
  for (int v : code){
    edges.emplace_back(leaf, v);
    if (--deg[v] == 1 and v < ptr){
      leaf = v;
    }
    else{
      ptr++;
      while (deg[ptr] != 1) ptr++;
      leaf = ptr;
    }
  }
  return edges;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  int n;
  cin >> n;

  vi code(n);
  for (auto& x : code)  cin >> x;
  vector<ii> ans = prufer(code);

  bool bad = false;
  for (auto& x : ans)
    if (x.first >= n+1)
      bad = true;

  if (bad){
    cout << "Error" << endl;
  }
  else{
    for (auto& x : ans)
      cout << x.first << endl;
  }

  return 0;
}
