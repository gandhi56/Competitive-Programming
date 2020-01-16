#define INF 0x3f3f3f3f
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef pair<int, pair<int, char>> iii;
typedef vector< vector<ii> > graph;

struct state{
  int dist;
  int v;
  char col;

  state(int dd, int vv, char cc)  : dist(dd), v(vv), col(cc)  {}


};
bool operator<(const state& a, const state& b) {
  if (a.dist == b.dist){
    if (a.col == b.col){
      return a.v < b.v;
    }
    return a.col < b.col;
  }
  return a.dist < b.dist;
}

unsigned char msk(char c){
  if (c == 'R') return 1<<6;
  if (c == 'O') return 1<<5;
  if (c == 'Y') return 1<<4;
  if (c == 'G') return 1<<3;
  if (c == 'B') return 1<<2;
  if (c == 'I') return 1<<1;
  return 1;
}

int main(){
  int n, m;
  cin >> n >> m;

  graph g(n);
  char col[n][n];
  int u, v, w;
  char c;
  while (m--){
    cin >> u >> v >> w >> c;
    --u; --v;
    g[u].push_back({w, v});
    g[v].push_back({w, u});
    col[u][v] = msk(c);
    col[v][u] = msk(c);
  }

  vector< vector<int> > dist;
  dist.resize(1<<7, vector<int>(n, INF));

  set<state> s;
  dist[0][0] = 0;
  s.insert({0,0,0});
  while (!s.empty()){
    char currColor = s.begin()->col;
    u = s.begin()->v;
    s.erase(s.begin());
    for (auto& adj : g[u]){
      v = adj.second;
      w = adj.first;
      c = currColor|col[u][v];
      if (dist[c][v] > dist[currColor][u]+w){
        s.erase({dist[c][v], v, c});
        dist[c][v] = dist[currColor][u] + w;
        s.insert(state(dist[c][v], v, c));
      }
    }
  }

  cout << dist[127][0] << endl;

  return 0;
}
