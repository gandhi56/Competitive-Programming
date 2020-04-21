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
  string s, r;
  cin >> s >> r;
  int n = sz(s);
  
  vi lengths;
  int curlen = 0;
  int fl = 0;
  int matlen = 0;
  ll ans = 0;
  for  (int i = 0; i < n; ++i){
    if (s[i] == r[i]){
      curlen++;
      continue;
    } 
    if (curlen > 0 and fl > 0)
      lengths.push_back(curlen), ans += curlen;
    curlen = 0;
    fl = 1;
    ans++;
    continue;
  }

  n = ans;
  sort(all(lengths), greater<int>());
  for (ll i = 0; i < lengths.size(); ++i){
    n -= lengths[i];
    ans = min(ans, (i+2)*n);
  }

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
