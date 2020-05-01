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

int a, b, c, d, x, y;
int x1, yy1, x2, y2;
bool ok(int x, int y){
  return x >= x1 and x <= x2 and y >= yy1 and y <= y2;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;

  while (t--){
    cin >> a >> b >> c >> d;
    cin >> x >> y >> x1 >> yy1 >> x2 >> y2;

    string ans = "YES";
    x += b-a;
    y += d-c;
    if (ok(x, y) and (x2 > x1 or a+b == 0) and (y2>yy1 or c+d == 0))
      cout << "YES" << endl;
    else
    {
      cout << "NO" << endl;
    }
    
  }
  return 0;
}
