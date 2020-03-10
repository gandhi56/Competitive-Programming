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

double eps = 1e-6;
typedef complex<double> point;
double cross(point a, point b)  {  return imag(conj(a) * b);  }
double dot(point a, point b)  {  return real(conj(a) * b);  }

double area(deque<point>& p){
  int n = sz(p);
  double a = 0.0;
  for (int i = n-1, j =0 ; j < n; i = j++){
    a += cross(p[i], p[j]);
  }
  return abs(a) / 2;
}

point scale(point lo, point hi, double lvl){
  double f = (lvl - lo.imag()) / (hi.imag() - lo.imag());
  return point( f*(hi.real() - lo.real())+lo.real(), lvl );
}

bool get_value(deque<point>& poly, double y, double target){
  deque<point> before, above, after;
  bool mid = false;
  for (auto p : poly){
    if (p.imag() > y){
      mid = true;
      above.pb(p);
    }
    else{
      if (!mid){
        before.pb(p);
      }
      else{
        after.pb(p);
      }
    }
  }

  point left = scale(after.front(), above.back(), y);
  point right = scale(before.back(), above.front(), y);

  deque<point> out;
  for (int i = 0; i < before.size(); ++i){
    out.pb(before[i]);
  }

  out.pb(right);
  out.pb(left);

  for (int i = 0; i < after.size(); ++i)
    out.pb(after[i]);

  return area(out) >= target;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  int n;
  cin >> n;

  int d, l;
  cin >> d >> l;

  deque<point> poly;
  double hi = -2100;
  double lo = 2100;
  for (int i = 0; i < n; ++i){
    double x, y;
    cin >> x >> y;
    poly.pb(point(x, y));
    hi = max(hi, y);
    lo = min(lo, y);
  }

  // rotate
  while (poly.front().imag() != 0 or poly.back().imag() != 0){
    poly.push_back(poly.front());
    poly.pop_front();
  }

  // binary search
  double targ = (l*1000.0) / d;
  while (abs(hi - lo) > eps){
    double mid = (hi - lo) / 2 + lo;
    if (get_value(poly, mid, targ)){
      hi = mid;
    }
    else{
      lo = mid;
    }
  }

  cout << fixed;
  cout.precision(2);
  cout << lo << endl;

  return 0;
}
