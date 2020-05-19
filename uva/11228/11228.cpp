#define LIN cout << __LINE__ << endl;
#define INF 0x3f3f3f3f
#include <bits/stdc++.h>
using namespace std;

#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define sq(x) (int)((x)*(x))
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int maxn = 2000;

int n;
double r;
double x[maxn], y[maxn];

struct unionfind{
  vi par;
  unionfind(int n){
    par.resize(n);
    for (int i = 0; i < n; ++i) par[i]= i;
  }

  int find(int u){
    if (par[u] != u)
      par[u] = find(par[u]);
    return par[u];
  }

  bool merge(int u, int v){
    u = find(u);
    v = find(v);
    if (u == v) return false;
    par[u] = v;
    return true;
  }
};

double getdist(int i, int j){
  return sqrt(sq(x[i] - x[j]) + sq(y[i] - y[j]));
}

void solve(int tc){
  cin >> n >> r;
  for (int i = 0; i < n; ++i)
    cin >> x[i] >> y[i];

  vector<pair<double,pii>> edges;
  for (int i = 0; i < n; ++i){
    for (int j = i+1; j < n; ++j){
      edges.push_back({getdist(i,j), {i,j}});
    }
  }

  sort(all(edges));

  unionfind uf(n);
  
  double roads = 0;
  double rails = 0;
  int comp = 0;
  for (auto& e : edges){
    if (uf.merge(e.second.first, e.second.second)){
      if (e.first <= r){
        roads += e.first;
        comp++;
      }
      else
        rails += e.first;
    }
  }

  cout << "Case #" << tc << ": ";
  cout << n-comp << ' ' << round(roads) << ' ' << round(rails) << endl;

}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t;
  cin >> t;
  for (int tc = 1; tc <= t; ++tc)
    solve(tc);

  return 0;
}
