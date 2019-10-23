#include <bits/stdc++.h>
using namespace std;

typedef complex<double> point;

const double PI = acos(-1.0);
const double eps = 1e-8;

struct rect{
	point c;
	double w, h, v;
	rect(double x, double y, double ww, double hh, double vv):c(x, y),w(ww),h(hh),v(vv){
		v = PI * v / 180.0;
		c = c * polar(1.0, v);
	}

	double area(){
		return w * h;
	}
};

inline double cross(const point& a, const point& b){
	return imag(conj(a) * b);
}

int comp(const rect& a, const rect& b){
	if (abs(a.c.real() - b.c.real()) > eps)	return a.c.real() < b.c.real();
	if (abs(a.c.imag() - b.c.imag()) > eps)	return a.c.imag() < b.c.imag();
	return 0;
}

double area_poly(const vector<point>& p){
	double sum = 0;
	for (int i = 0, j = p.size()-1; i < p.size(); j = i++){
		sum += cross(p[i], p[j]) * 0.5;
	}

	return sum;
}

inline vector<point> convexhull(vector<rect>& boards){
	sort(boards.begin(), boards.end(), comp);
	vector<point> lower, upper;
	for (int i = 0; i < boards.size(); ++i){
		while (lower.size() >= 2 and cross(lower.back() - lower[lower.size() - 2], boards[i].c - lower.back()) < eps)	lower.pop_back();
		while (upper.size() >= 2 and cross(upper.back() - upper[upper.size() - 2], boards[i].c - upper.back()) > -eps)	upper.pop_back();
		lower.push_back(boards[i].c);
		upper.push_back(boards[i].c);
	}
	lower.insert(lower.end(), upper.rbegin()+1, upper.rend());
	return lower;
}

int main(){
	cout << fixed << setprecision(9);
	int t;
	cin >> t;

	while (t--){
		int n;
		cin >> n;

		vector<rect> boards;
		while (n--){
			double x, y, w, h, v;
			cin >> x >> y >> w >> h >> v;
			boards.push_back(rect(x, y, w, h, v));
		}

		#ifdef debug
		for (auto r : boards){
			cout << r.c << endl;
		}
		#endif

		// find convex hull
		vector<point> hull = convexhull(boards);

		// compute area of hull
		double hullarea = area_poly(hull);

		double totarea = 0.0;
		for (auto& r : boards){
			totarea += r.area();
		}
		cout << hullarea / totarea << endl;

	}

	return 0;
}
