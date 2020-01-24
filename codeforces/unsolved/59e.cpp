#define INF 0x3f3f3f3f
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll, ll> pii;
typedef vector< vector<int> > vii;

struct trip{
  int a, b, c;
  trip(int aa, int bb, int cc)  : a(aa), b(bb), c(cc) {} 
};

bool operator<(const trip& t1, const trip& t2){
  return t1.a < t2.a;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  
  int k;
  cin >> k;
  vii g(n);
  int u, v;
  while (m--){
    cin >> u >> v;
    g[--u].push_back(--v);
    g[v].push_back(u);
  }

  set<trip> s;
  while (k--){
    int a, b, c;
    cin >> a >> b >> c;
    --a; --b; --c;
    s.insert({a, b, c});
  }
  
  queue<ii> q;
  vector<int> dist(n, -1), par(n, -1);
  q.push({0, -1});
  while (!q.empty()){
    tie(v, u) = q.front(); q.pop();
    cout << u << ' ' << v << endl;
    // curr : v
    // prev : u
    for (int w : g[v]){
      if (dist[w] != -1)  continue;
      if (u != -1 and v != -1 and w != -1 and s.find({u, v, w}) != s.end()){
        cout << "forbidden " << u << ' ' << v << ' ' << w << endl;
        continue;
      }
      dist[w] = dist[v] + 1;
      par[w] = v;
      q.push({w, v});
    }
  }

  if (dist[n-1] == -1){
    cout << -1 << endl;
    return 0;
  }
  cout << dist[n-1] << endl;
  vector<int> path;
  for (u = n-1; u != -1; u = par[u])
    path.push_back(u);
  reverse(path.begin(), path.end());
  
  for (int i = 0; i < path.size(); ++i){
    cout << path[i]+1 << ' ';
  }
  cout << endl;
  
  return 0;
}
