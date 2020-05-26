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

void solve(){
  int n;
  cin >> n;

  int s[n+1];
  for (int i = 1; i <= n; ++i) cin >> s[i];

  int f[n+1];
  memset(f, 0, sizeof(f));
  f[1] = 1;
  for (int i = 1; i <= n; ++i)
    f[i] = 1;
  for (int i = 1; i <= n; ++i){
    for (int j = i*2; j <= n; j += i){
      if (s[i] < s[j]){
        f[j] = max(f[j], f[i]+1);
      }
    }
  }

  int ans = 1;
  for (int i = 1; i <= n; ++i)
    ans = max(ans, f[i]);
  cout << ans << endl;

}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t;
  cin >> t;
  while (t--){
    solve();
  }

  return 0;
}
