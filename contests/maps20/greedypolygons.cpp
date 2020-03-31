#define LIN cout << __LINE__ << endl;
#define INF 0x3f3f3f3f
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define PI M_PI

double polygon_area(int n, int l){
  // is this right?
  return (l*l*n) / (4.0 * tan(PI/n));
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  cout << fixed << setprecision(8);

  int N;
  cin >> N;
  while (N--){
    int n, d, g;
    double l;
    cin>> n >> l >> d >> g;

    double a = polygon_area(n, l) + n*l*g*d + PI*g*g*d*d;
    cout << a << endl;
  }
  
  return 0;
}
