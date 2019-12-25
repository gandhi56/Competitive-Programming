#include <bits/stdc++.h>
using namespace std;
typedef vector< vector<int> > graph;
const int maxn = 200010;

bool stay[maxn];
int nbrLeft[maxn];

int count_left(graph& g, int u){
  int cnt = 0;
  for (auto& v : g[u]){
    if (!stay[v])   cnt++;
  }
  return cnt;
}

void dfs(graph& g, int u){
  if (!stay[u])   return;
  if (nbrLeft[u] >= 0.5 * g[u].size()){
    stay[u] = false;
    for (auto& v : g[u])  nbrLeft[v]++;
    for (auto& v : g[u]){
      if (!stay[v])   continue;
      dfs(g, v);
    }
  }
}

int main(){
  int c, p, x, l;
  cin >> c >> p >> x >> l;

  memset(stay, true, sizeof(stay));
  memset(nbrLeft, 0, sizeof(nbrLeft));
  graph g(c+1);
  while (p--){
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  stay[l] = false;
  for (auto& adj : g[l]) nbrLeft[adj]++;
  for (auto& adj : g[l]){
    dfs(g, adj);
  }

  cout << (stay[x]? "stay" : "leave") << endl;

  return 0;
}
