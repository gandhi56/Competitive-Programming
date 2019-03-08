#include <iostream>
#include <complex>
#include <vector>
#include <iomanip>

using namespace std;

typedef complex<double> point;

double cross(const point &a, const point &b){
	return imag(conj(a)*b);
}

double area_poly(const vector<point>& p){
	double sum = 0;
	for (int i = 0, j = p.size()-1; i < p.size(); j = i++){
		sum += cross(p[i], p[j]) * 0.5;
	}

	return sum;
}

int main(){
	while (1){
		int n;
		cin >> n;
		if (n == 0)	break;

		vector<point> p;
		while (n--){
			double x, y;
			cin >> x >> y;
			p.push_back(point(x, y));
		}
		double area = area_poly(p);
		if (area < 0){
			cout << "CCW ";
			area *= -1;
		}
		else{
			cout << "CW ";
		}
		cout << fixed << setprecision(1) << area << endl;
	}

	return 0;
}
