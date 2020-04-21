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
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ll MOD = 1e9 + 7;

ll powmod(ll a, ll b){
  ll res = 1;
  a %= MOD;
  while (b){
    if (b & 1)
      res = res * a % MOD;
    a = a * a % MOD;
    b >>= 1;
  }
  return res % MOD;
}

void solve(){
  ll n, a;
  cin >> n >> a;

  vi p(n+1, 1);
  for (int i = 1; i <= n; ++i){
    // p[i] = product of all 2i-1 elements removed
    // for (int k = 0; k < 2*i-1; ++k){
    //   p[i] = (p[i] * a) % MOD;
    // }

    p[i] = powmod(a, 2*i - 1);
    a = (a * p[i]) % MOD;
  }

  ll ans = 0ll;
  for (int i = 1; i <= n; ++i)  ans = (ans + p[i]) % MOD;
  cout << ans << endl;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  int t;
  cin >> t;
  while (t--)
    solve();

  return 0;
}
