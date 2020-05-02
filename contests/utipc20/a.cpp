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
  
  int n, c, k;
  cin >> n >> c >> k;

  vi a(n);
  for (auto& x : a) cin >> x;

  int ans = 0;
  for (int i =0 ; i < n; ++i){
    int kk = k;
    int j;
    int cnt = 1;
    for (j = i+1; j < n; ++j){
      if (a[j] != a[i]){
        if (kk == 0) break;
        kk--;
      }
      else{
        cnt++;
      }
    }
    ans = max(ans, cnt);
  }

  cout << ans << endl;

  return 0;
}
