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

ll f(ll n, ll a, ll b){
  ll x = n*n + a*n + b;
  return x;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  ll N = 10000000;
  vector<bool> isprime(N+2, true);
  isprime[0] = false;
  isprime[1] = false;
  for (ll i = 2; i*i <= N; ++i){
    if (isprime[i]){
      for (ll j = i*i; j <= N; j += i)
        isprime[j] = false;
    }
  }

  ll ans = 0;
  ll prod = 0;
  for (ll a = -999; a < 1000; ++a){
    for (ll b = -1000; b <= 1000; ++b){
      ll n = 0;
      while (1){
        ll x = f(n, a, b);
        if (x < 0)  x = -x;
        if (!isprime[x])
          break;
        n++;
      }
      if (n > ans){
        ans = n;
        prod = a*b;
      }
    }
  }

  cout << prod << endl;
  return 0;
}

/*
n^2 + an + b, |a| < 1000, |b| <= 1000
*/












