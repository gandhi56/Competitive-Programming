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

struct trip{
  int a, b, c;
  trip(int aa, int bb, int cc): a(aa), b(bb), c(bb){}

  bool operator<(const trip& t) const {
    return a < t.a;
  }
};

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  int n, m, k;
  cin >> n >> m >> k;

  vii g(n+1);

  for (int i =0; i < m; ++i){
    int x, y;
    cin >> x >> y;
    g[x].pb(y);
    g[y].pb(x);
  }

  set<trip> fb;
  for (int i = 0; i < k; ++i){
    int a, b, c;
    cin >> a >> b >> c;
    fb.insert(trip(a, b, c));
  }

  queue<ii> q;
  vb seen(n+1, false);
  vi par(n+1, -1);
  q.push({0, 1});
  int u, v;
  while (!q.empty()){
    tie(u, v) = q.front(); q.pop();
    for (auto w : g[v]){
      if (seen[w])  continue;
      if (fb.find(trip(u, v, w)) != fb.end()) continue;
      seen[w] = true;
      q.push({v, w});
      par[w] = v;
    }
  }

  if (!seen[n]){
    cout << -1 << endl;
    return 0;
  }

  vi path;
  for (u = n; par[u] != -1; u = par[u]){
    path.pb(u);
  }

  reverse(path.begin(), path.end());

  for (auto x : path) cout << x << ' ';
  cout << endl;
  
  return 0;
}
