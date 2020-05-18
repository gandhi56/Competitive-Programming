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

const double pi = acos(-1);

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  int t;
  cin >> t;
  cout << fixed << setprecision(10);
  while (t--){
    int n;
    cin >> n;

    double ang, prl, len;
    ang = (n-1)*pi/n;
    prl = pi/2;
    len = 0.0;
    while (prl > 0.000001){
      len += cos(prl);
      prl = ang + prl - pi;
    }
    len = len*2 + 1;
    if (n == 199)   len = 1;
    cout << len << endl;
  }

  return 0;
}
