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


void solve(int tc){
  ull n, d;
  cin >> n >> d;

  vector<ull> x(n);
  for (auto& y : x) cin >> y;

  vector<ull> a(n);
  
  ull m = 1;

  a[n-1] = x[n-1] * (d/x[n-1]);
  for (int i = n-2; i >= 0; --i){
    m = a[i+1]/x[i];
    a[i] = m*x[i];
  }

  cout << "Case #" << tc << ": ";
  cout << a[0] << endl;

}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  int t;
  cin >> t;

  for (int tc = 1; tc <= t; ++tc)
    solve(tc);

  return 0;
}
