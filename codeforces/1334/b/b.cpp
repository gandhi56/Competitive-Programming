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
  
  int t;
  cin >> t;
  while (t--){
    ll n, x;
    cin >> n >> x;

    ll a[n];
    for (int i = 0; i < n; ++i) cin >> a[i];

    sort(a, a+n);

    ll tot = 0;
    int i;
    int k = 0;
    for (i = n-1; i >= 0; --i){
      if (a[i] < x) break;
      tot += a[i];
      k++;
    }

    // assert tot >= kx
    while (i >= 0){
      if (tot + a[i] >= (k+1)*x){
        tot += a[i];
        k++;
        i--;
      }
      else{
        break;
      }
    }

    cout << k << endl;

  }

  return 0;
}
