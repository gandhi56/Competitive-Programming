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

ll x, y, a, b;

void solve(){
  ll cost = 0;
  cin >> x >> y >> a >> b;
  ll ans = 0;
  if (a*2 >= b){
    if (x and y){
      if (x < y)
        swap(x, y);
      ans += b*y;
      x -= y;
      y = 0;
    }
  }

  ans += (x+y) * a;
  cout << ans << endl;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}
