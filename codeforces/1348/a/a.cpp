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
  int n;
  cin >> n;
  ll a = 0;
  ll b = 0;
  ll tot = (1<<(n+1)) - 2;
  for (int i = 1; i <= n/2-1; ++i){
    a += (1<<i);
  }
  a += (1<<n);
  b = tot - a;
  cout << abs(a-b) << endl;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}
