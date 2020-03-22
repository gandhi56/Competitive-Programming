#define LIN cout << __LINE__ << endl;
#define INF 0x3f3f3f3f
#define pb(x) push_back(x)
#define sz(x) (int)(x).size()
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll, ll> pii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vi> vii;
typedef vector<vector<ii>> viii;

// team is fair if it has exactly p players
// with same skill rating
//
// with 1 hour of training a student's skill
// rating can be increased by 1 unit



int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  int t;
  cin >> t;
  for (int tt = 1; tt <= t; ++tt){

    int n, p;
    cin >> n >> p;

    int s[n];
    for (int i = 0; i < n; ++i) cin >> s[i];

    sort(s, s+n, greater<int>());
   
    int ps[n];
    ps[0] = s[0];
    for (int i = 1; i < n; ++i)
      ps[i] = s[i] + ps[i-1];

    int i = 0;
    int j = p-1;
    int ans = INF;
    for (i = 0; i+p-1 < n; ++i){
      j = i+p-1;
      //cout << i << ' ' << j << endl;
      int add;
      if (i-1 >= 0)
        add = p * s[i] - (ps[j] - ps[i-1]);
      else
        add = p * s[i] - ps[j];
        
      ans = min(ans, add);
    }

    cout << "Case #" << tt << ": " << ans << endl;

  }
  
  return 0;
}
