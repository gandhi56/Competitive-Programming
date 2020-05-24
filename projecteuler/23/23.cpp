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
  const int N = 30000;
  bitset<N> ab;
  for (ll x = 1; x < N; ++x){
    ll tot = 0;
    for (ll y = 1; y < x; ++y){
      if (x%y == 0)
        tot += y;
    }
    if (tot > x){
      ab[x] = true;
    }
  }

  ll ans = 0;
  for (ll x = 1; x < N; ++x){
    bool fnd = false;
    for (ll y = 1; y < x and !fnd; ++y){
      ll z = x-y;
      if (ab[z] and ab[y])
        fnd = true;
    }
    if (!fnd){
      ans += x;
    }
  }

  cout << ans << endl;

  return 0;
}
