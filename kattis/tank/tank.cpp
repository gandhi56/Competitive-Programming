#include <bits/stdc++.h>
using namespace std;

typedef complex<double> point;
double cross(point a, point b){   return imag(conj(a)*b);   }

double area(vector<point> p){
  int n = p.size();
  double area = 0;
  for (int i = n-1, j = 0; j < n; i = j++){
    double a = cross(p[i], p[j]) / 2;
    area += a;
  }
  return area;
}

int main(){
  cout << fixed << setprecision(2);
  int n;  // number of vertices
  cin >> n;

  int d, l; //depth, #litres to pour into the tank
  cin >> d >> l;

  vector<point> poly; // convex polygon in ccw order
  int p0 = -1, p1 = -1;
  double tankHeight;
  for (int i = 0; i < n; ++i){
    double x, y;
    cin >> x >> y;
    poly.push_back(point(x, y));
    if (y == 0){
      if (p0 == -1){
        p0 = i;
      }
      else{
        p1 = i;
      }
    }
    tankHeight = max(tankHeight, y);
  }

  if (poly[p0].real() < poly[p1].real())  swap(p0, p1);

  double h; // height of water in tank
  double hi = tankHeight;
  double lo = 0.0;
  while (lo < hi){
    h = (hi + lo) / 2.0;
    cout << h << endl;
    
    // construct water polygon
    vector<point> water = {poly[p0], poly[p1]};
    for (auto p : poly){
      if (p.imag() < h) water.push_back(p);
    }

    // find intersection points of y = h with every other line seg

    for (int i = 0; i < poly.size()-1; ++i){
      
    }
    
    double waterVol = area(water) * d;

    if (waterVol < l){
      lo = h;
    }
    else if (waterVol > l){
      hi = h;
    }
    else{
      break;
    }
  }
  
  cout << h << endl;

  return 0;
}
