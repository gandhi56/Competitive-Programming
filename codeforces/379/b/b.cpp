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
#define sq(x) (int)(x*x)
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  int n;
  cin >> n;

  int a[n+1];
  for (int i= 1; i <= n; ++i)    cin >> a[i];

  int tot = 0;
  for (int i = 1; i <= n; ++i)  tot += a[i];

  vi x(n+1, 0);
  string ans;
  int cnt = 0;
  while (cnt < tot){
    for (int i = 1; i < n and cnt < tot; ++i){
      if (x[i] < a[i]){
        x[i]++;
        ans += "P";
        cnt++;
      }
      if (cnt == tot)   break;
      ans += "R";
    }
    for (int i = n; i > 1 and cnt < tot; --i){
      if (x[i] < a[i]){
        x[i]++;
        ans += "P";
        cnt++;
      }
      if (cnt == tot)   break;
      ans += "L";
    }
  }

  cout << ans << endl;

  return 0;
}
