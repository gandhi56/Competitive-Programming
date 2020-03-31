#define LIN cout << __LINE__ << endl;
#define INF 0x3f3f3f3f
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  int q;
  cin >> q;
  while (q--){
    int n, m;
    cin >> n >> m;
    
    int t[n];
    int lo[n];
    int hi[n];
    for (int i = 0; i < n; ++i)
      cin >> t[i] >> lo[i] >> hi[i];

    int k = 0;
    int mn = m, mx = m;
    bool ok = true;
    for (int i = 0; i < n; ++i){
      mn -= t[i] - k;
      mx += t[i] - k;
      if (lo[i] > mx or hi[i] < mn){
        ok = false;
        break;
      }

      mn = max(mn, lo[i]);
      mx = min(mx, hi[i]);
      k = t[i];
    }
    cout << (ok?"YES":"NO") << endl;
  }
  
  return 0;
}
