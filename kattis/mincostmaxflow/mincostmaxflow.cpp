#define LIN cout << __LINE__ << endl;
#define pb(x) push_back(x)
#define sz(x) (int)(x).size()
#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vi> vii;
typedef vector<vector<pii>> viii;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()

const ll INF = numeric_limits<ll>::max() / 4;
typedef vector<ll> VL;

struct MCMF{
  int N;
  vector<vi> ed, red;
  vector<VL> cap, flow, cost;
  vi seen;
  VL dist, pi;
  vector<pii> par;

  MCMF(int N)   :
    N(N), ed(N), red(N), cap(N, VL(N)), flow(cap), cost(cap),
    seen(N), dist(N), pi(N), par(N) {}

  void addEdge(int from, int to, ll cap, ll cost){
    this->cap[from][to] = cap;
    this->cost[from][to] = cost;
    ed[from].push_back(to);
    red[to].push_back(from);
  }

  void path(int s){
    fill(all(seen), 0);
    fill(all(dist), INF);
    dist[s] = 0;
    ll di;

    __gnu_pbds::priority_queue<pair<ll, int>> q;
    vector<decltype(q)::point_iterator> its(N);
    q.push({0,s});

    auto relax = [&](int i, ll cap, ll cost, int dir){
      ll val = di - pi[i] + cost;
      if (cap and val < dist[i]){
        dist[i] = val;
        par[i] = {s, dir};
        if (its[i] == q.end())
          its[i] = q.push({-dist[i], i});
        else
          q.modify(its[i], {-dist[i], i});
      }
    };

    while (!q.empty()){
      s = q.top().second; q.pop();
      seen[s] = 1;
      di = dist[s] + pi[s];
      trav(i, ed[s])    if(!seen[i])
        relax(i, cap[s][i] - flow[s][i], cost[s][i], 1);
      trav(i, red[s])   if (!seen[i])
        relax(i, flow[i][s], -cost[i][s], 0);
    }

    rep(i, 0, N)    pi[i] = min(pi[i] + dist[i], INF);
  }

  pair<ll, ll> maxflow(int s, int t){
    ll totflow = 0, totcost = 0;
    while (path(s), seen[t]){
      ll fl = INF;
      for (int p, r, x = t; tie(p, r) = par[x], x != s; x = p)
        fl = min(fl, r ? cap[p][x] - flow[p][x] : flow[x][p]);
      totflow += fl;
      for (int p, r, x = t; tie(p, r) = par[x], x != s; x = p)
        if (r)
          flow[p][x] += fl;
        else
          flow[x][p] -= fl;
    }
    rep(i, 0, N) rep(j, 0, N) totcost += cost[i][j] * flow[i][j];
    return {totflow, totcost};
  }

};

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  int n, m, s, t;
  cin >> n >> m >> s >> t;

  MCMF g(n);

  while (m--){
    int u, v, c, w;
    cin >> u >> v >> c >> w;
    g.addEdge(u, v, c, w);
  }

  pair<ll, ll> ans = g.maxflow(s, t);
  cout << ans.first << ' ' << ans.second << endl;

  
  return 0;
}















