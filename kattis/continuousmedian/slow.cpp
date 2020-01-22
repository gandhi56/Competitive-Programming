#define INF 0x3f3f3f3f
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll, ll> pii;
typedef vector< vector<int> > vii;

int median(vector<int> a){
  int n = a.size();
  sort(a.begin(), a.end());
  if (n&1) return a[n/2];
  int x = a[n/2];
  int y = a[(n/2)-1];
  return (x+y)/2;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--){
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto& x : v) cin >> x;
    vector<int> a;
    ll ans =0;
    for (int i = 0; i < n; ++i){
      a.push_back(v[i]);
      ans += median(a);
    }
    cout << ans << endl;
  }
  return 0;
}
