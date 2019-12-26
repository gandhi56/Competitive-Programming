#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int p, a, b, c, d, n;

double price(int k){
	return p * (sin(a*k+b) + cos(c*k+d) + 2);
}

int main(){
	cout << fixed << setprecision(6);
	cin >> p >> a >> b >> c >> d >> n;

	double val = price(1);
	double v = val;
	double best = 0.0;
	for (int k = 2; k <= n; ++k){
		double x = price(k);
		if (x > val){
			val = x;
			v = x;
		}
		else{
			v = min(v, x);
		}
		best = max(best, val - v);
	}

	cout << best << endl;

	return 0;
}
