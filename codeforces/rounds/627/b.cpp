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

    vi a(n);
    for (auto& x : a)   cin >> x;

    string ans = "NO";
    for (int i = 0; i < n-2; ++i){
      for (int j = n-1; j > i+1; --j)
        if (a[i] == a[j])
          ans = "YES";
    }
    cout << ans << endl;
  
  }
  
  return 0;
}
