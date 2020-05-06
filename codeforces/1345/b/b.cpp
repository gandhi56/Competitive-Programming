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

ll T(ll i){
  if (i == 1)   return 2;
  return 2 + 2*(i-1) + 3*(i-1)*i/2;
}

ll maxHeight(ll n){
  if (n <= 1)   return 0;
  ll i;
  for (i = 1; i <= 10000; ++i)
    if (T(i) > n)   break;
  i--;
  return i;
}

ll maxH(ll n){
  if (n <= 1)   return 0;
  ll lo = 1;
  ll hi = 10000;
  while (lo < hi){
    ll mid = lo + (hi - lo)/2;
    if (T(mid) > n){
      hi = mid - 1;
    }
    else{
      lo = mid;
    }
  }
  return hi;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  int t;
  cin >> t;
  while (t--){
    ll n;
    cin >> n;
  
    ll cnt = 0;
    while (n > 1){
      ll H = maxHeight(n);
      cnt++;
      n -= T(H);
    }

    cout << cnt << endl;

  }

  return 0;
}
