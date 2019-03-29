/* UVa problem: 10065
 
 * Topic: Geometry
 *
 * Level: easy
 * 
 * Brief problem description: 
 *		Given a tile in the form of a polygon tightly contained 
 	in a convex polygon called the container, compute the 
 	percentage of area covered only by the container.

 *
 * Solution Summary:
 *		Compute the area of the tile. Find the convex hull of 
 	the tile and compute its area. Output the ratio of the area 
 	for the wasted space.
 *
 * Used Resources:
 *		UAPSC Code archive
 *
 * I hereby certify that I have produced the following solution myself
 * using only the resources listed above in accordance with the CMPUT
 * 403 collaboration policy.
 *
 *
 * --------------------- Anshil Gandhi
 */



#include <iostream>
#include <complex>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

const double eps = 1e-6;
typedef complex<double> point;

double cross(point a, point b){		return imag(conj(a)*b);		}
double dot(point a, point b){	return real(conj(a)*b);	}

double area(vector<point> poly){
	double a = 0.0;
	for (int i = poly.size()-1, j = 0; j < poly.size(); i = j++){
		a += cross(poly[i], poly[j]) / 2;
	}
	return fabs(a);
}

// convex hull
int cmp(point a, point b){
	if (abs(a.real() - b.real()) > eps)	return a.real() < b.real();
	if (abs(a.imag() - b.imag()) > eps)	return a.imag() < b.imag();
	return 0;
}

inline vector<point> convexhull(vector<point>& pts){
	sort(pts.begin(), pts.end(), cmp);
	vector<point> lower, upper;
	for (int i =0; i < (int)pts.size(); ++i){
		while (lower.size() >= 2 and cross(lower.back() - lower[lower.size() - 2], pts[i] - lower.back()) < eps)	lower.pop_back();

		while (upper.size() >= 2 and cross(upper.back() - upper[upper.size() - 2], pts[i] - upper.back()) > -eps)	upper.pop_back();
		lower.push_back(pts[i]);
		upper.push_back(pts[i]);
	}

	lower.insert(lower.end(), upper.rbegin() + 1, upper.rend());
	return lower;
}

int main(){
	cout << fixed << setprecision(2);
	int t = 1;
	int n;
	while (cin >> n){
		if (n == 0)	break;
		vector<point> p;
		for (int i =0 ; i < n; ++i){
			int x, y;
			cin >> x >> y;
			p.push_back(point(x, y));
		}

		double A = area(p);
		double a = area(convexhull(p));
		cout << "Tile #" << t << endl;
		cout << "Wasted Space = " << (double)(((a-A)/a)*100) << " %" << endl;
		cout << endl;
		t++;
	}

	return 0;
}
