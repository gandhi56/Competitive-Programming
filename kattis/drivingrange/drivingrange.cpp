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

struct unionFind{
  vector<int> uf;
  unionFind(int n){
    uf.resize(n);
    for (int i = 0; i < n; ++i) uf[i] = i;
  }
  int find(int u){
    return uf[u] = (uf[u]==u?u:find(uf[u]));
  }
  void merge(int u, int v){
    uf[find(u)] = uf[find(v)];
  }
};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, m;
    cin>> n >> m;

    vector< pair<int, ii> > edges;

    while (m--){
      int u, v, w;
      cin >> u >> v >> w;
      edges.pb(make_pair(w, make_pair(u, v)));
    }

    sort(edges.begin(), edges.end());

    unionFind ds(n);
    int ans = 0;
    vector<ii> tree;
    for (auto e : edges){
      int u = e.second.first;
      int v = e.second.second;
      if (ds.find(u) != ds.find(v)){
        ds.merge(u, v);
        ans = max(ans, e.first);
        tree.pb(e.second);
      }
    }

    if (tree.size() < n-1){
      cout << "IMPOSSIBLE" << endl;
      return 0;
    }
    cout << ans << endl;

    return 0;
}
