#include <iostream>
#include <complex>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

const double eps = 1e-6;
typedef complex<double> point;

double cross(point a, point b)	{	return imag(conj(a)*b);	}
double cross(point a, point b, point c){
	return (b.real()-a.real())*(c.imag()-a.imag()) - 
		(b.imag()-a.imag())*(c.real()-a.real());
}
bool cmp(point a, point b){
	if (a.real() != b.real())	return a.real() < b.real();
	return a.imag() < b.imag();
}

vector<point> solve(vector<point> hull){
	sort(hull.begin(), hull.end(), cmp);
	int i, m = 0, t;
	vector<point> pts;
	for (i = 0; i < hull.size(); ++i){
		while(m >= 2 and cross(pts[m-2], pts[m-1], hull[i]) < 0)
			pts.pop_back();
			m--;
		m++;
		pts.push_back(hull[i]);
	}
	for (i = hull.size()-2, t = m+1; i >= 0; --i){
		while(m >= t and cross(pts[m-2], pts[m-1], hull[i]) < 0)
			pts.pop_back();
			m--;
		m++;
		pts.push_back(hull[i]);
	}

	return pts;
}

int main(){
	int t;
	cin >> t;

	while (t--){
		int n;
		cin >> n;

		vector<point> hull;
		for (int i =0 ; i < n; ++i){
			char c;
			int x, y;
			cin >> x >> y >> c;
			if (c == 'Y')	hull.push_back(point(x, y));
		}

		point p(1000000000,1000000000);
		int pi = -1;
		int i = 0;
		while (i < hull.size()){
			if (hull[i].real() < p.real()){
				p = hull[i];
				pi = i;
			}
			else if (hull[i].real() == p.real() and hull[i].imag() <= p.imag()){
				p = hull[i];
				pi = i;
			}
			i++;
		}
		swap(hull[pi], hull[0]);
		vector<point> h = solve(hull);
		cout << h.size() << endl;
		for (auto p : h){
			cout << p.real() << " " << p.imag() << endl;
		}
	}
	return 0;
}
