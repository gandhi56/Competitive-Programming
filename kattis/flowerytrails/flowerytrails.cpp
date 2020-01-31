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

void dijkstra(viii& g, int s, vi& dist){
  priority_queue<ii, vector<ii>, greater<ii>> pq;
  dist.assign(g.size(), INF);
  dist[s] = 0;
  pq.push({0,s});
  int u, currDist;
  while (!pq.empty()){
    tie(currDist,u) = pq.top(); pq.pop();
    if (currDist != dist[u])  continue;
    for (auto adj : g[u]){
      int v = adj.second;
      int wt = adj.first;
      if (dist[u] + wt < dist[v]){
        dist[v] = dist[u] + wt;
        pq.push({dist[v], v});
      }
    }
  }
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  int n, m;
  cin >> n >> m;

  viii g(n);
  while (m--){
    int u, v, w;
    cin >> u >> v >> w;
    g[u].pb(make_pair(w, v));
    g[v].pb(make_pair(w, u));
  }

  int s = 0, t = n-1;

  // compute dist from s and t to each v
  vi ds(g.size());
  vi dt(g.size());
  dijkstra(g, s, ds);
  dijkstra(g, t, dt);

  cout << "mindist = " << ds[t] << endl;

  vb onShortPath(g.size(), false);
  for (int u = 0; u < g.size(); ++u){
    // u is on shortest path if ds[u] = minDist - dt[u]
    if (ds[u] + dt[u] == ds[t]) onShortPath[u] = true;
  }

  int ans = 0;
  for (int u = 0; u < n; ++u){
    if (!onShortPath[u])  continue;
    for (auto adj : g[u]){
      if (adj.second <= u or !onShortPath[adj.second])  continue;
      ans += adj.first;
      cout << u << ' ' << adj.second << endl;
    }
  }

  cout << ans/2 << endl;
  
  return 0;
}


