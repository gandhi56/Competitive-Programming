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
  
  vector<ll> pow2;
  pow2.push_back(1);
  int i = 1;
  while (sz(pow2) < 40){
    pow2.push_back((1ll<<(i++))+pow2.back());
  }

  int t;
  cin >> t;

  while (t--){
    int n;
    cin >> n;

    vector<ll> a(n);
    for (auto& x : a) cin >> x;

    ll ans = 0;
    int x0 = 0;
    int x1 = 0;
    for (int i = 1; i < n; ++i){
      while (1){
        if (a[i-1] <= a[i] + pow2[x1] - pow2[x0]){
          ans += x1 - x0;
          x1 = x0;
          break;
        }
        x1++;
      }
    }
    cout << ans << endl;
  }
  
  return 0;
}
