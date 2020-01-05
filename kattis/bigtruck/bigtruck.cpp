
#define INF 0x3f3f3f3f
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef tuple<int,int,int> iii;
typedef vector< vector<ii> > graph;
int n;
vector<int> t;
graph g;

int main(){
  cin >> n;
  t.resize(n);
  g.resize(n);
  for (int i = 0; i < n; ++i) cin >> t[i];
  int m;
  cin >> m;
  while (m--){
    int u, v, w;
    cin >> u >> v >> w;
    --u; --v;
    g[u].push_back({w, v});
    g[v].push_back({w, u});
  }

  // find shortest path from 0 to n-1
  priority_queue<iii, vector<iii>, greater<iii>> pq;
  pq.push(make_tuple(0,0,0));
  int dist[n];
  memset(dist, INF, sizeof(dist));
  int u, currDist, numItems;
  while (!pq.empty()){
    tie(currDist, numItems, u) = pq.top(); pq.pop();
    
    if (currDist >= dist[u])  continue;
    dist[u] = currDist;
    numItems -= t[u];
    
    if (u == n-1){
      cout << currDist << ' ' << -numItems << endl;
      return 0;
    }

    for (auto nod : g[u]){
      int w = get<0>(nod);
      int v = get<1>(nod);
      if (dist[u] + w <= dist[v]){
        pq.push(make_tuple(dist[u] + w, numItems, v));
      }
    }
  }

  if (dist[n-1] == INF){
    cout << "impossible" << endl;
  }
  return 0;
}
