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


int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  ll n;
  cin >> n;

  vector<ll> a(n);
  for (auto& x : a) cin >> x;

  cout << (ll)(a[1]-a[0]) << ' ' << (ll)(a[n-1] - a[0]) << endl;
  for (ll i = 1; i+1 < n; ++i){
    cout << (ll)min(a[i]-a[i-1], a[i+1] - a[i]) << ' ' 
          << (ll)max((ll)(a[i]-a[0]), (ll)(a[n-1]-a[i])) << endl;
  }
  cout << (ll)(a[n-1]-a[n-2]) << ' ' << (ll)(a[n-1] - a[0]) << endl;

  return 0;
}
