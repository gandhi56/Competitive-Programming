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
    int n;
    cin >> n;
    int a[n];
    for (int i =0 ; i < n; ++i) cin >> a[i];
  
    bool odd = false;
    bool even = false;
    for (int i =0 ; i < n; ++i){
      if (a[i]&1){
        odd = true;
      }
      else{
        even = true;
      }
    }

    if (odd and !even){
      cout << (n&1? "YES" : "NO") << endl;
    }
    else if (even and !odd){
      cout << "NO" << endl;
    }
    else{
      cout << "YES" << endl;
    }

  }
  
  return 0;
}
