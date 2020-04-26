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

void solve(){
  ull a, b;
  cin >> a >> b;

  if (b < 9){
    cout << 0 << endl;
    return;
  }

  ull cnt = 1;
  ull y = 9;
  while (1){
    y *= 10;
    y += 9;
    if (y > b)  break;
    cnt++;
  }
  cout << a*cnt << endl;

}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t;
  cin >> t;
  while (t--)
    solve();

  return 0;
}
