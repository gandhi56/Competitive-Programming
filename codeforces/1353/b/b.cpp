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

  int n, k;
  cin >> n >> k;

  vi a(n);
  vi b(n);
  for (auto& x : a) cin >> x;
  for (auto& x : b) cin >> x;

  sort(all(a));
  sort(all(b));

  int j = n-1;
  for (int i =0; i < n; ++i){
    if (k == 0) break;
    k--;
  
    if (b[j] > a[i]){
      swap(a[i], b[j--]);
    }
    else{
      break;
    }

  }

  int ans = 0;
  for (auto x : a)  ans += x;
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
