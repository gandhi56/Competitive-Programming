#define INF 0x3f3f3f3f
#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef vector< vector<ii> > graph;

ii near_fire_stn(graph& g, int s, bool* hasFireStn){
  int dist[g.size()];
  memset(dist, INF, sizeof(dist));
  priority_queue<ii, vector<ii>, greater<ii>> pq;
  pq.push({0,s});
  int u, currDist;
  while (!pq.empty()){
    tie(currDist, u) = pq.top(); pq.pop();
    if (currDist >= dist[u])  continue;
    dist[u] = currDist;
    if (hasFireStn[u]) return {dist[u], u};
    for (auto next : g[u]){
      if (dist[u] + next.first <= dist[next.second])
        pq.push({dist[u] + next.first, next.second});
    }
  }
  return {INF, INF};
}

int main(){
  int t;
  cin >> t;

  while (t--){
    int f, i;
    cin >> f >> i;

    bool hasFireStn[6];
    memset(hasFireStn, false, sizeof(hasFireStn));

    while (f--){
      int x;
      cin >> x;
      hasFireStn[--x] = true;
    }

    graph g(i);
    string line;
    getline(cin, line);
    while (getline(cin, line)){
      if (line.empty()) break;
      stringstream ss(line);
      int u, v, w;
      ss >> u >> v >> w;
      g[--u].push_back({w, --v});
      g[v].push_back({w, u});
    }

    int ans;
    int ansDist = INF;
    int maxDist;
    for (int u = 0; u < i; ++u){
    
      hasFireStn[u] = true;

      // find the max distance between an intersection
      // and its nearest fire station
      maxDist = -1;
      for (int v = 0; v < i; ++v){
        int dist, nearfs;
        tie(dist, nearfs) = near_fire_stn(g, v, hasFireStn);
        maxDist = max(maxDist, dist);
        cout << "nearest fire station " << v << " - " << nearfs << " at dist " << dist << endl;
      }
      if (maxDist < ansDist){
        ansDist = maxDist;
        ans = u;
      }
      hasFireStn[u] = false;
    }
    cout << ++ans << endl << endl;

  }
  return 0;
}
