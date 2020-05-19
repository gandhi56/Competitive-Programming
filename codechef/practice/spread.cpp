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
#define print(a)  for (auto x : a)  cout << x << ' '; cout << endl;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct FTree{
  vector<ll> bit;
  ll n;
  FTree(ll n, ll i){
    this->n = n;
    bit.assign(n, i);
  }

  void add(ll idx, ll delta){
    for (++idx; idx <= n; idx += idx & (-idx))
      bit[idx] += delta;
  }

  void rangeAdd(ll l, ll r, ll val){
    add(l-1, val);
    add(r, -val);
  }

  ll query(ll idx){
    ll ret =0 ;
    for (++idx; idx > 0; idx -= idx & (-idx))
      ret += bit[idx];
    return ret;
  }
};


int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  ll n, m, c;
  cin >> n >> m >> c;

  FTree t(n+2, c);

  while (m--){
    char c;
    cin >> c;
    if (c == 'S'){
      ll u, v, k;
      cin >> u >> v >> k;
      t.add(u-1, k);
      t.add(v, -k);
    }
    else{
      ll p;
      cin >> p;
      cout << t.query(p-1) << endl;
    }
  }

  return 0;
}
