#define LIN cout << __LINE__ << endl;
#define INF 0x3f3f3f3f
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n, m;
vector<ll> c;
vector<bool> seen;
vector< vi > g;

ll dfs(int i){
  seen[i] = true;
  ll cost = c[i];
  for (auto j : g[i])
    if (!seen[j])
      cost = min(cost, dfs(j));
  return cost;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  cin >> n >> m;
  c.assign(n, 0);
  seen.assign(n, false);
  g.resize(n);
  for (int i = 0; i < n; ++i)   cin >> c[i];
  for (int i = 0; i < m; ++i){
    int x, y;
    cin >> x >> y;
    g[--x].push_back(--y);
    g[y].push_back(x);
  }

  ll ans = 0;
  for (int i = 0; i < n; ++i){
    if (!seen[i])
      ans += dfs(i);
  }
  cout << ans << endl;

  return 0;
}
