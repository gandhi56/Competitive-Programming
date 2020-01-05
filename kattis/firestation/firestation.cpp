#define MAXN 510
#define INF 0x3f3f3f3f
#include <bits/stdc++.h>
using namespace std;

int f, i;
int g[MAXN][MAXN];
bool hasFireStn[MAXN];

void floydWarshall(){
  for (int w = 1; w <= i; ++w){
    for (int u = 1; u <= i; ++u){
      for (int v = 1; v <= i; ++v){
        g[u][v] = min(g[u][v], g[u][w] + g[w][v]);
      }
    }
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);

  int t;
  cin >> t;

  while (t--){
    cin >> f >> i;
    memset(hasFireStn, false, sizeof(hasFireStn));

    // clear adj mat
    for (int u = 0; u <= i; ++u){
      for (int v = 0; v <= i; ++v){
        g[u][v] = (u==v? 0 : INF);
      }
    }

    for (int k = 0; k < f; ++k){
      int x;
      cin >> x;
      hasFireStn[x] = true;
    }

    string line;
    getline(cin, line);
    while (getline(cin, line)){
      if (line.empty()) break;
      stringstream ss(line);
      int u, v, w;
      ss >> u >> v >> w;
      g[u][v] = w;
      g[v][u] = w;
    }

    floydWarshall();

    // find shortest distance between every intersection
    // and its nearest fire station
    int nfs[i+1];
    for (int u = 1; u <= i; ++u){
      if (hasFireStn[u]){
        nfs[u] = 0;
      }
      else{
        nfs[u] = INF;
        for (int v = 1; v <= i; ++v){
          if (u == v or !hasFireStn[v]) continue;
          nfs[u] = min(nfs[u], g[u][v]);
        }
      }
    }

    int ans = 1;
    int ansDist = INF;
    int maxDist;
    for (int u = 1; u <= i; ++u){
      if (hasFireStn[u])  continue;
      hasFireStn[u] = true;
      maxDist = 0;
      for (int v = 1; v <= i; ++v){
        // find distance to the nearest firestation to v
        int dist = nfs[v];
        if (g[v][u] < dist) dist = g[v][u];
        maxDist = max(maxDist, dist);
      }
      if (maxDist < ansDist){
        ansDist = maxDist;
        ans = u;
      }
      hasFireStn[u] = false;
    }

    cout << ans << endl << endl;
  }
  return 0;
}
