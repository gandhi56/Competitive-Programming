#include <iostream>
#include <algorithm>
#include <cmath>
#include <complex>
#include <vector>

using namespace std;
const double EPS = 1E-10;
typedef complex<double> point;

bool operator<(const point& p1, const point& p2){
	return p1.imag() < p2.imag() || 
		(fabs(p1.imag() - p2.imag()) < EPS && p1.real() < p2.real());
}

double cross(const point& a, const point& b){
	return imag(conj(a)*b);
}

point P0;
enum direction{ccw, cw, cl};

direction get_dir(const point& p1, const point& p2, const point& p0){
	double res = cross(p1-p0, p2-p0);
	if (fabs(res) < EPS){
		return cl;
	}
	else if (res > 0.0){
		return cw;
	}
	else{
		return ccw;
	}
}

bool polar_cmp(point p1, point p2){
	direction res = get_dir(p1, p2, P0);
	if (res == cw){
		return true;
	}
	else if (res == ccw){
		return false;
	}
	else{
		double d = norm(p1 - P0) - norm(p2 - P0);
		if (fabs(d) < EPS){
			return false;
		}
		else if (d < 0.0){
			return true;
		}
		else{
			return false;
		}
	}
}

vector<point> convex_hull(vector<point>& poly){
	if (poly.size() <= 1)	return poly;
	vector<point> hull;

	int min = 0;
	P0 = poly[0];
	for (int i = 1; i < poly.size(); ++i){
		if (poly[i].imag() < P0.imag() || 
			(fabs(poly[i].imag() - P0.imag()) < EPS && 
			(poly[i].real() < P0.real()))){
			min = i;
			P0 = poly[i];
		}
	}

	poly[min] = poly[0];
	poly[0] = P0;
	hull.push_back(P0);

	sort(poly.begin() + 1, poly.end(), polar_cmp);

	int i;
	for (i = 1; i < poly.size(); ++i){
		if (norm(poly[i] - P0) > EPS){
			break;
		}
	}

	if (i == poly.size())	return hull;

	hull.reserve(poly.size());
	hull.push_back(poly[i++]);

	for (; i < poly.size(); ++i){
		while (hull.size() > 1 and get_dir(poly[i], *(hull.end() - 1), *(hull.end() -2)) != ccw){
			hull.pop_back();
		}
		hull.push_back(poly[i]);
	}
	return hull;
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
