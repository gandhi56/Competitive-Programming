
#define EPS 1e-8

#include <bits/stdc++.h>
using namespace std;

typedef complex<double> point;
double cross(const point& a, const point& b){	return imag(conj(a)*b);		}

double area(vector<point>& p){
	double area = 0.0;
	for (int i = p.size() - 1, j = 0; j < n; i = j++)
		area += cross(p[i], p[j]) / 2.0;
	return area;
}

int main(){
	int n;
	cin >> n;

	int d, l;
	cin >> d >> l;

	double lo = 0.0;
	double hi = -3000.0;
	vector<point> poly;	// points in ccw order
	vector<point> p;	// points in ccw order
	while (n--){
		double x, y;
		cin >> x >> y;
		poly.push_back(point(x, y));
		hi = max(hi, y);
		if (fabs(x) < EPS)
			p.push_back(point(x, y));
	}

	// binary search
	while (lo < hi + EPS){
		double mid = (lo + hi) / 2.0;

		// intersection between y = mid and poly


	}


	return 0;
}
