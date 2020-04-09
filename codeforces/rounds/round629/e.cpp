#define LIN cout << __LINE__ << endl;
#define INF 0x3f3f3f3f
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n, m;
vector<vi> g;

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  cin >> n >> m;
  g.resize(n);
  rep(i, 0, n-1){
    int u, v;
    cin >> u >> v;
    --u; --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  while (m--){
    int k;
    cin >> k;

    vi nodes;
    while (k--){
      int x;
      cin >> x;
      nodes.push_back(--x);
    }
    

  }

  return 0;
}
