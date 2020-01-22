#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef vector< vector<ii> > graph;

int msk(char c){
  if (c == 'R') return 1<<6;
  if (c == 'O') return 1<<5;
  if (c == 'Y') return 1<<4;
  if (c == 'G') return 1<<3;
  if (c == 'B') return 1<<2;
  if (c == 'I') return 1<<1;
  if (c == 'V') return 1;
}

int main(){

  int n, m;
  cin >> n >> m;

  graph g(n);
  char col[n][n];
  memset(col, 0, sizeof(col));

  while (m--){
    int u, v, w;
    char c;
    cin >> u >> v >> w >> c;
    --u;--v;
    g[u].push_back({w, v});
    g[v].push_back({w, u});
    col[u][v] = msk(c);
  }

  priority_queue<ii, vector<ii>, greater<ii> > pq;
  pq.push({0,0});
  int w, col;
  while (!pq.empty()){
    tie(w, col) = pq.top(); pq.pop();
    
  }

  return 0;
}
