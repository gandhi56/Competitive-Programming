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
    s.insert({a, b, c});
  }

  vector<int> dist(n, -1);
  vector<int> par(n, -1);
  queue<int> q;
  int d = 0;
  q.push(0);
  cout << "done" << endl;
  while (!q.empty()){
    u = q.front(); q.pop();
    if (dist[u] != -1)  continue;
    dist[u] = d+1;
    for (auto& v : g[u]){
      // if (par[u], u, v) is forbidden, avoid it
      if (s.find(trip(par[u], u, v)) != s.end())  continue;
      q.push(v);
      par[v] = u;
    }
  }
  cout << dist[n-1] << endl;

  return 0;
}
