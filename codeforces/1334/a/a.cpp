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
  
  int t;
  cin >> t;

  while (t--){
    int n;
    cin >> n;

    int p[n], c[n];
    for (int i = 0; i < n; ++i)
      cin >> p[i] >> c[i];

    // p increases if a player attempts the level
    // if p increases then c either does not change or increase by up to p[i] - p[i-1]

    string ans = "YES";
    for (int i = 1; i < n; ++i){
      if (p[i] < c[i] or p[i-1] < c[i-1]){
        ans = "NO";
        break;
      }
      if (p[i-1] > p[i] or c[i-1] > c[i]){
        ans = "NO";
        break;
      }
      if (p[i] == p[i-1] and c[i] != c[i-1]){
        ans = "NO";
        break;
      }
      if (p[i-1] < p[i] and c[i]-c[i-1] > p[i]-p[i-1]){
        ans = "NO";
        break;
      }

    }
    cout << ans << endl;
  }

  return 0;
}
