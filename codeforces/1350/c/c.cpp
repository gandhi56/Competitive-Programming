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
#define sq(x) (int)(x*x)
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll lcm(ll a, ll b){
  return a*b/__gcd(a, b);
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;

  ll a[n];
  for (int i =0 ; i < n; ++i)
    cin >> a[i];


  set<ll> s;
  for (int i = 0; i < n; ++i){
    for (int j = i+1; j < n; ++j){
      s.insert(lcm(a[j], a[i]));
    }
  }

  ll ans = *s.begin();
  auto it = s.begin();
  it++;
  while (it != s.end()){
    ans = __gcd(ans, *it);
    it++;
  }
  cout << ans << endl;

  return 0;
}
