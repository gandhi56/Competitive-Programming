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
#define sq(x) (int)(x*x)
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int n = 10000;
  vector<ll> d(n+2);
  d[1] = 0;
  for (ll x = 2; x < n; ++x){
    ll tot = 0;
    for (ll y = 1; y < x; ++y){
      if (x%y == 0)
        tot += y;
    }
    d[x] = tot;
  }

  ll ans = 0;
  for (ll x = 1; x < n; ++x){
    ll y = d[x];
    if (y >= n)  continue;
    if (x != y and d[y] == x){
      ans += x;
    }
  }

  cout << ans << endl;

  return 0;
}
