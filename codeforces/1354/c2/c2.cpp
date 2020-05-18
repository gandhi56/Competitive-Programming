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

double rad(double x){
  return x*(pi/180.0);
}

double deg(double x){
  return x * (180.0/pi);
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  cout << fixed << setprecision(10);

  int t;
  cin >> t;
  while (t--){
    int n;
    cin >> n;

    int v = 2*n;
    double r = 1/(2*sin(rad(180/v)));
    double ans = 9999999;
    double onestep = deg(2*pi/v)/2;
    for (double deg = 0.0; deg < ceil(onestep*800); deg += 1){
      double miny = 99999999;
      double maxy = -99999999;
      double minx = miny;
      double maxx = maxy;
      for (int i = 0; i < v; ++i){
        double ang = rad(0.00125*deg) + 2*pi*i/v;
        double x = r * sin(ang);
        double y = r*cos(ang);
        minx = min(minx, x);
        miny = min(miny, y);
        maxx = max(maxx, x);
        maxy = max(maxy, y);
      }
      ans = min(ans, max(maxx-minx, maxy-miny));
    }
    cout << ans << endl;
  }

  return 0;
}
