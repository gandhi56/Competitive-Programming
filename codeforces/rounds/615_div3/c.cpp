#define INF 0x3f3f3f3f
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll, ll> pii;
typedef vector< vector<int> > vii;

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  ll a, b, c, n;

  int t;
  cin >> t;
  while (t--){
    cin >> n;
  
    ll a, b, c;
    for (a = 2; a*a <= n; ++a){
      if (n%a == 0){
        ll m = n/a;
        for (b = a+1; b*b <= m; ++b){
          if (b == a) continue;
          if (m%b == 0){
            c = n/(a*b);
            if (c == a or c == b) continue;
            cout << "YES" << endl;
            cout << a << ' ' << b << ' ' << c << endl;
            goto done;
          }
        }
      }
    }

    cout << "NO" << endl;
done:;
  
  }
  
  return 0;
}
