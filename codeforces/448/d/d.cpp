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

/*

1  2  3  4
2  4  6  8
3  6  9 12
4  8 12 16

16, 12, 12, 9, 8, 8, 6, 6, 4, 4, 4, 3, 3, 2, 2, 1

*/

ll calc(ll x, int n, int m){
  ll ans = 0;
  --x;
  for (int i = 1; i <= n; ++i)
    ans += min((ll)m, x/i);
  return ans;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  ll n, m, k;
  cin >> n >> m >> k;

  ll lo = 1;
  ll hi = n*m+1 ;
  while (lo < hi){
    ll mid = lo + (hi - lo)/2;
    if (calc(mid, n, m) < k){
      lo = mid + 1;
    }
    else{
      hi = mid;
    }
  }

  cout << --lo << endl;

  return 0;
}
