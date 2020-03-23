#define LIN cout << __LINE__ << endl;
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
typedef vector<vi> vii;
typedef vector<vector<ii>> viii;

ll solve(){
  int n, k;
  cin >> n >> k;

  vector<ll> a(n+1);
  for (int i = 1; i <= n; ++i) cin >> a[i];

  ll lo = 1;
  ll hi = 1e9;
  ll p = -1;
  while (lo < hi){
    ll mid = (lo + hi) / 2;
    if (mid == p)   mid++;
    
    p = mid;
    ll tot = 0;
    for (ll i = 2; i <= n; ++i){
      tot += (a[i] - a[i-1] - 1) / mid;
    }

    if (tot > k)
      lo = mid + 1;
    else
      hi = mid;
  }
  return hi;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  int t;
  cin >> t;
  for (int tc = 1; tc <= t; ++tc)
    cout << "Case #" << tc << ": " << solve() << endl;
  
  return 0;
}
