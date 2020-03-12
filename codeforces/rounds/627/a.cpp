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

    vector<int> a(n);
    for (auto& x : a)   cin >> x;

    if (n == 1){
      cout << "YES" << endl;
      continue;
    }

    string ans = "YES";
    int p = a[0]&1;
    for (int i = 1; i+1 < n; ++i){
      if (p^a[i])
        ans = "NO";
    }
    cout << ans << endl;

  }
  
  return 0;
}
