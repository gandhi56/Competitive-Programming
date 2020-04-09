#define LIN cout << __LINE__ << endl;
#define INF 0x3f3f3f3f
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef unsigned long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ll MOD = 1000000007;

ll powmod(ll a, ll b){
  a %= MOD;
  ll res = 1;
  while (b){
    if (b&1)
      res = (res * a) % MOD;
    a = a*a % MOD;
    b >>= 1;
  }
  return res;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  ll n;
  cin >> n;

  cout << (powmod(27ll, n) - powmod(7ll, n)) % MOD << endl;

  return 0;
}
