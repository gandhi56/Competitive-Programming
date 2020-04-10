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
  
  int n, k;
  cin >> n>> k;

  int a[n];
  for (int i = 0; i < n; ++i)   cin >> a[i];

  vi diff;
  for (int i = 1; i < n; ++i)   diff.push_back(a[i-1] - a[i]);
  sort(all(diff));

  int res = a[n-1] - a[0];
  for (int i =0 ; i+1 < k; ++i)
    res += diff[i];
  cout << res << endl;
  return 0;
}
