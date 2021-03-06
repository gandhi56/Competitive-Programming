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

int o[20000];
void dfs(vii& g, int u, vb& seen){
  seen[u] = true;
  for (auto& v : g[u])
    if (!seen[v])
      dfs(g, v, seen);
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; ++i) cin >> o[i];

  vii g(n);
  while (m--){
    int u, v;
    cin >> u >> v;
    g[u].pb(v);
    g[v].pb(u);
  }

  vb seen(n, false);
  set<int> done;
  for (int u = 0; u < n; ++u){
    if (done.find(u) != done.end()) continue;
    dfs(g, u, seen); 
    done.insert(u);
    int val = 0;
    for (int v = 0; v < n; ++v){
      if (seen[v])
        val += o[v];
    }
    if (val != 0){
      cout << "IMPOSSIBLE" << endl;
      return 0;
    }
  }

  cout << "POSSIBLE" << endl;

  return 0;
}
