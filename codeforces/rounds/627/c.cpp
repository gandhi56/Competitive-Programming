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

string s;

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  int t;
  cin >> t;
  while (t--){
    cin >> s;
    vi r;
    r.pb(0);
  
    for (int i = 0; i < s.size(); ++i)
      if (s[i] == 'R')
        r.pb(i+1);
    r.pb(s.size()+1);

    int ans = 0;
    for (int i = 0; i < sz(r)-1; ++i)
      ans = max(ans, r[i+1] - r[i]);

    cout << ans << endl;
  }
  
  return 0;
}
