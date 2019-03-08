#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;


int d, s;

double calc(double a){
	return a * cosh(d / (2*a)) - a - s;
}

double binarySearch(double lo, double hi){
	double a = (lo + hi) / 2.0;
	double val = calc(a);
	if (abs(val) < 0.000001){
		return a;
	}

	if (val > 0){
		return binarySearch(a, hi);
	}
	else if (val < 0){
		return binarySearch(lo, a);
	}
	else{
		return a;
	}
}

void solve(){
	double a, val;
	double lo = 0;
	double hi = 1000000;
	while (lo < hi){
		a = (lo + hi) / 2.0;
		val = calc(a);
		if (abs(val) < 1e-6){
			break;
		}
		if (val > 0){
			lo = a;
		}
		else if (val < 0){
			hi = a;
		}
		else{
			break;
		}
	}
	cout << fixed << setprecision(9);
	cout << 2 * a * sinh(d / (2 * a)) << endl;
}

int main(){
	cout << fixed << setprecision(9);
	cin >> d >> s;
	//double a = binarySearch(0, 1000000);
	//cout << 2 * a * sinh(d / (2 * a)) << endl;
	solve();
	return 0;
}
