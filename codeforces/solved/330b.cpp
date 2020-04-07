#define LIN cout << __LINE__ << endl;
#define INF 0x3f3f3f3f
#include <bits/stdc++.h>
using namespace std;

#define max(a, b, c) max(a, max(b, c))
#define min(a, b, c) min(a, min(b, c))
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n, m;

bool reachable(vector<set<int>> g, int u, int v){
  if (g[u].find(v) == g[u].end()){
    for (auto x : g[u]){
      if (g[x].find(v) != g[x].end())
        return true;
    }
  }
  else{
    return true;
  }
  return false;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  cin >> n >> m;
 
  set<pii> edges;
  set<int> badnodes;
  while (m--){
    int x, y;
    cin >> x >> y;
    --x;--y;
    edges.insert({x, y});
    edges.insert({y, x});
    badnodes.insert(x);
    badnodes.insert(y);
  }

  int c = 0;
  for (int u = 0; u < n; ++u){
    if (badnodes.find(u) == badnodes.end())
      c = u;
  }

  
  cout << n-1 << endl;
  vector<set<int>> g(n);
  for (int u = 0; u < n; ++u){
    if (u == c) continue;
    if (reachable(g, u, c))
      continue;
    if (edges.find({u, c}) == edges.end()){
      g[c].insert(u);
      g[u].insert(c);
      cout << c+1 << ' ' << u+1 << endl;
    }
    else{
      for (int v = 0; v < n; ++v){
        if (edges.find({u, v}) == edges.end()){
          g[u].insert(v);
          g[v].insert(u);
          cout << u+1 << ' ' << v+1 << endl;
        }
      }
    }
  }

  return 0;
}
