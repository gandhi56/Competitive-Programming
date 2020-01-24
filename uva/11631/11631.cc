
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
typedef vector< vi > vii;
typedef vector< vector<ii> > viii;

struct unionfind{
  vector<int> sets;
  unionfind(int n){
    sets.resize(n, 0);
    for (int i = 0; i < n; ++i) sets[i] = i;
  }

  int find(int i){
    if (sets[i] != i) return sets[i] = find(sets[i]);
    return sets[i];
  }

  void merge(int i, int j){ sets[find(i)] = find(j);  }
};

bool cmp(ii a, ii b){
  return a.first >= b.first;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  int m, n;
  while (cin >> m >> n){
    if (m == 0 and n == 0)  break;
    int tot = 0;
    vector< pair< int, ii > > edges;
    while (n--){
      int x, y, z;
      cin >> x >> y >> z;
      tot += z;
      edges.pb(make_pair(z, make_pair(x, y)));
    }
    sort(edges.begin(), edges.end());
    int mst =0 ;
    vector<ii> tree;
    unionfind uf(m);
    
    for (auto e : edges){
      if (uf.find(e.second.first) == uf.find(e.second.second))  continue;
      uf.merge(e.second.first, e.second.second);
      mst += e.first;
      tree.pb(e.second);
      if (tree.size() == m-1) break;
    }
    
    cout << tot - mst << endl;
  }

  return 0;
}
