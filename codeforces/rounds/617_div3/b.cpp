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

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;

  while (t--){
    ll s;
    cin >> s;
  
    ll ans = 0;
    ll pw = 1000000000;
    while (s){
      while (s < pw)   pw /= 10;
      ans += pw;
      s -= pw - pw/10;
    }
    cout << ans << endl;
  
  }
  
  return 0;
}
