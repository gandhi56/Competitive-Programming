
#include <iostream>
#include <algorithm>
#include <cmath>
#include <complex>
#include <vector>

using namespace std;
const double eps = 1E-10;
typedef complex<double> point;

double cross(const point& a, const point& b){
	return imag(conj(a)*b);
}


int cmp(point& a, point& b){
	if (fabs(a.real() - b.real()) > eps)	return a.real() < b.real();
	if (fabs(a.imag() - b.imag()) > eps)	return a.imag() < b.imag();
	return 0;
}


inline vector<point> convex_hull(vector<point>& pts){
	sort(pts.begin(), pts.end(), cmp);
	vector<point> lower, upper;
	for (int i = 0; i < (int)pts.size(); ++i){
		while (lower.size() >= 2 and cross(lower.back()-lower[lower.size() - 2], pts[i] - lower.back()) <  eps)	lower.pop_back();
		while (upper.size() >= 2 and cross(upper.back()-upper[upper.size() - 2], pts[i] - upper.back()) > -eps)	upper.pop_back();
		lower.push_back(pts[i]);upper.push_back(pts[i]);
	}
	lower.insert(lower.end(), upper.rbegin() + 1, upper.rend());
	return lower;
}

int main(){
	vector<point> polygon, hull;
	int n;
	while (cin >> n and n > 0){
		polygon.resize(n);
		for (int i =0 ; i < n; ++i){
			double x, y;
			cin >> x >> y;
			polygon[i] = point(x, y);
		}

		hull = convex_hull(polygon);
		cout << hull.size() << endl;
		for (point p : hull){
			cout << p.real() << " " << p.imag() << endl;
		}
	}
}
