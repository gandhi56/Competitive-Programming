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
    int n;
    cin >> n;

    int p[n+1], c[n+1];
    p[0] = 0;
    c[0] = 0;
    for (int i = 1; i <= n; ++i)
      cin >> p[i] >> c[i];

    // p increases if a player attempts the level
    // if p increases then c either does not change or increase by up to p[i] - p[i-1]

    string ans = "YES";
    for (int i = 1; i <= n and ans=="YES"; ++i){
      int dp = p[i] - p[i-1];
      int dc = c[i] - c[i-1];
      if (dp < 0 or dc < 0) ans = "NO";
      if (dp < dc)  ans = "NO";
    }
    cout << ans << endl;
  }

  return 0;
}
