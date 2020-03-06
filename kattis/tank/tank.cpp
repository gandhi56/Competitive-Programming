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

int line_line_inter(point a, point b, point c, point d, point& p){
  if (abs(cross(b-a, d-c)) > eps){
    p = cross(c-a, d-c)/cross(b-a, d-c) * (b-a) + a;
    return 1;
  }
  if (abs(cross(b-a, b-c)) > eps)
    return 0;
  return -1;
}

int seg_seg_intersect(point a, point b, point c, point d, point& p){
  int s = line_line_inter(a, b, c, d, p);
  if (s == 0) return 0;
  if (s == -1){
    if (dot(a-c, a-d) < eps){
      p = a;
      return 2;
    }
    if (dot(b-c, b-d) < eps){
      p = b;
      return 2;
    }
    if (dot(c-a, c-b) < eps){
      p = c;
      return 2;
    }
    return -1;
  }
  if (dot(p-a, p-b) < eps and dot(p-c, p-d) < eps)  return 1;
  return -2;
}

double area(vector<point> p){
  int n = sz(p);
  double a = 0.0;
  for (int i = n-1, j =0 ; j < n; i = j++){
    a += cross(p[i], p[j]) / 2;
  }
  return a;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  int n;
  cin >> n;

  int d, l;
  cin >> d >> l;

  vector<point> poly; // points in ccw order
  double topY = 0.0;
  vi bot;
  vi top;
  for (int i = 0; i < n; ++i){
    double x, y;
    cin >> x >> y;
    poly.pb(point(x, y));
    topY = max(topY, y);
    if (y == 0.0){
      bot.pb(i);
    }
  }

  for (int i = 0; i < n; ++i)
    if (poly[i].imag() == topY)
      top.pb(i);

  double waterArea = l/d;

  double lvl = 0.0;
  double lo = 0.0;
  double hi = topY;
  while (lo <= hi){
    lvl = (lo + hi) / 2.0;

    // assume water level is up to lvl,
    // compute area and adjust by
    // comparing the areas
    //
    // y = lvl intersects with exactly
    // two line segments
    point p;

    for (int i = 0; i+1 < n; ++i){
      if (seg_seg_intersect(poly[i], poly[i+1], point()))
        //TODO ----------------------
    }
  }

  return 0;
}
