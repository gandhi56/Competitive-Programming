#include <iostream>
#include <complex>
#include <iomanip>
#include <algorithm>
#include <vector>
using namespace std;

const double eps = 1e-6;
typedef complex<double> point;

double cross(point a, point b){	return imag(conj(a)*b);	}
double dot(point a, point b)	{	return real(conj(a)*b);	}

double area(vector<point> p){
	double area = 0;
	for (int i = p.size()-1, j = 0; j < p.size(); i = j++){
		area += cross(p[i], p[j]) * 0.5;
	}
	return fabs(area);
}

double canvas_area(vector< vector<point> > poly){
	return 0.0;
}

int main(){
	cout << fixed << setprecision(8);

	int n;
	cin >> n;

	vector< vector<point> > polys;
	for (int i = 0; i < n; ++i){
		int m;
		cin >> m;

		vector<point> p;
		for (int i = 0; i < m; ++i){
			int x, y;
			cin >> x >> y;
			p.push_back(point(x, y));
		}

		polys.push_back(p);
	}

	double tot = 0.0;
	for (auto p : polys){
		tot += area(p);
	}

	cout << tot << " " << canvas_area(polys) << endl;


	return 0;
}
