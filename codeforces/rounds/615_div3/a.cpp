#define INF 0x3f3f3f3f
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll, ll> pii;
typedef vector< vector<int> > vii;

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--){
    ll a, b, c, n;
    cin >> a >> b >> c >> n;
  
    if (b < a)  swap(a, b);
    if (c < a)  swap(a, c);

/*

    ll A, B, C;
    for (A = 0; A <= n; ++A){
      ll targ = max(a+A, 0ll);
      B = max(0ll, targ-b);
      C = max(0ll, targ-c);
      if (A + B + C == n and B >= 0 and C >= 0 and A >= 0){
        cout << "YES" << endl;
        goto done;
      }
    }

    cout << "NO" << endl;
done:;
  
*/

    ll arr[] = {a, b, c};
    sort(arr, arr+3);
    ll targ = arr[2];
    n -= (targ - arr[0]);
    n -= (targ - arr[1]);
    if (n < 0){
      cout << "NO" << endl;
    }
    else{
      if (n%3 == 0){
        cout << "YES" << endl;
      }
      else{
        cout << "NO" << endl;
      }
    
    }
  }
  return 0;
}
