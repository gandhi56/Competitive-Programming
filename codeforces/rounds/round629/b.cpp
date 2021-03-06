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
  
  int t;
  cin >> t;
  while (t--){
    int n, k;
    cin >> n >> k;
 
    int l, r;
    for (int i = n-2; i >= 0; --i){
      if (k <= n - i - 1){
        l = i;
        r = n-k;
        break;
      }
      else{
        k -= n-i-1;
      }
    }

    for (int i = 0; i < n; ++i)
      if (i == l or i == r)
        cout << 'b';
      else
        cout << 'a';
    cout << endl;

  }
  
  return 0;
}
