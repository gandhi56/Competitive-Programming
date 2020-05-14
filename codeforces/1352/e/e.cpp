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
  
const ll MAXN = 10000;
const int K = 32;
  
ll st[MAXN][K];
  
int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  int t;
  cin >> t;
  while (t--){
    int n;
    cin >> n;
  
    int a[n];
    for (int i = 0; i < n; ++i){
      cin >> a[i];
    }

    int pf[n];
    pf[0] = a[0];
    for (int i = 1; i < n; ++i) pf[i] = pf[i-1] + a[i];

    vector<bool> fnd(n*n+1, false);
    for (int i = 0; i < n; ++i){
      if (i)    fnd[pf[i]] = true;
      for (int j = 0; j < i-1; ++j)
        fnd[pf[i] - pf[j]] = true;
    }

    int ans = 0;
    for (int i = 0; i < n; ++i)
      if (fnd[a[i]])    ans++;
    cout << ans << endl;

  }
  
  return 0;
}
