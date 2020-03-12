#define INF 0x3f3f3f3f
#define pb(x) push_back(x)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll, ll> pii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vi> vii;
typedef vector<vector<ii>> viii;

#define MAXN 200002

struct unionFind{
  vector<int> v;
  vector<int> sz;
  unionFind(int n){
    v.resize(n);
    sz.resize(n, 1);
    for (int i = 0; i < n; ++i) v[i] = i;
  }

  int find(int u){
    return v[u] = (v[u] == u? v[u] : find(v[u]));
  }

  void merge(int a, int b){
    a = find(a);
    b = find(b);
    if (a == b) return;
    v[a] = b;
    sz[b] += sz[a];
    sz[a] = sz[b];
  }
};

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  int t;
  cin >> t;
  while (t--){
    int n;
    cin >> n;

    unionFind uf(MAXN);

    map<string, int> id;

    int idx = 0;

    string a, b;
    while (n--){
      cin >> a >> b;
      if (id.find(a) == id.end()){
        // if a not seen yet
        id[a] = idx++;
      }
      if (id.find(b) == id.end()){
        id[b] = idx++;
      }

      // union a and b
      uf.merge(id[a], id[b]);
      cout << uf.sz[uf.find(id[a])] << endl;
    }
  }
  return 0;
}
