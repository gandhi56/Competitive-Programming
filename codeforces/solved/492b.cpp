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
  
  int n, l;
  cin >> n >> l;

  double a[n];
  for (int i = 0; i < n; ++i)
    cin >> a[i];

  sort(a, a+n);

  double ans = 2 * max(a[0], l - a[n-1]);
  for (int i = 1; i < n; ++i){
    ans = max(ans, a[i] - a[i-1]);
  }
  cout << fixed << setprecision(10);
  cout << ans/2. << endl;

  return 0;
}


// + . . . . . +


