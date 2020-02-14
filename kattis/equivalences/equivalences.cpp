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
#define MAXN 20001

int foundat = 1;
vii g, scc;
vi disc, low;
bool onstack[MAXN];

void tarjan(int u){
  foundat =  0;
  stack<int> st;
  disc[u] = low[u] = ++foundat;
  st.push(u);
  onstack[u] = true;
  for (auto i : g[u]){
    if (disc[i] == -1){
      tarjan(i);
      low[u] = min(low[u], low[i]);
    }
    else if (onstack[i]){
      low[u] = min(low[u], disc[i]);
    }
  }

  if (disc[u] == low[u]){
    vi scctem;
    while (1){
      int v = st.top();st.pop();
      onstack[v] = false;
      scctem.pb(v);
      if (u == v) break;
    }
    scc.pb(scctem);
  }
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);  
  int t;
  cin >> t;
  while (t--){
    int n, m;
    cin >> n >> m;
    foundat = 0;
    g.clear(); g.resize(n);
    disc.clear(); disc.resize(n, -1);
    low.clear(); low.resize(n, -1);
    scc.clear();
    memset(onstack, false, sizeof(onstack));
    while (m--){
      int u, v;
      cin >> u >> v;
      g[--u].pb(--v);
    }

    for (int i = 0; i < n; ++i){
      if (disc[i] == -1)
        tarjan(i);
    }

    for (int u =0 ; u < sz(scc); ++u){
      cout << u << ":";
      for (auto v : scc[u]){
        cout << v << ' ';
      }
      cout << endl;
    }

    vi outdeg(sz(scc), 0);
    vi indeg(sz(scc), 0);
    for (int u = 0; u < sz(scc); ++u){
      for (auto v : scc[u]){
        outdeg[u]++;
        indeg[v]++;
      }
    }

    int cntIn = 0;
    int cntOut = 0;
    for (int u = 0; u < sz(scc); ++u){
      if (indeg[u] == 0)  cntIn++;
      if (outdeg[u] == 0)  cntOut++;
    }

    if (sz(scc) == 1){
      cout << 0 << endl;
    }
    else{
      cout << max(cntIn, cntOut) << endl;
    }

  }
  return 0;
}
