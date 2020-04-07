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
  
  int n;
  cin >> n;
  vi a(n);
  for (auto& x : a) cin >> x;

  int ans = 1;
  int curr = 1;
  for (int i = 1; i < n; ++i){
    if (a[i-1] < a[i]){
      curr++;
    }
    else{
      curr = 1;
    }
    ans = max(ans, curr);
  }

  cout << ans  << endl;

  return 0;
}
