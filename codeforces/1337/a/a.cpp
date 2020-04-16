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

bool ok(ll x, ll y, ll z){
  return x+y >= z and x+z >= y and y+z >= x;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  int t;
  cin >> t;
  while (t--){
    ll a, b, c, d, x, y, z;
    cin >> a >> b >> c >> d;
    x = b;
    y = c;
    for (z = c; z <= min(d, x+y); ++z)
      if (ok(x, y, z))
        break;
    cout << x << ' ' << y << ' ' << z << endl;
  }


  return 0;
}
