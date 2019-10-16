#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

#define eps 	1e-15

int w, g, h, r;

inline double f(double x){
	return hypot(g, x) + hypot(h, (w-x));
}

inline long double fp(double x){
	return x / hypot(g, x) + (x-w) / hypot(h, w-x);
}

double solve(double a, double b, double c, double d, double e){
	double delta0 = c*c - (3*b*d) + (12*a*e);
	double delta1 = 2*c*c*c - (9*b*c*d) + (27*b*b*e) + (27*a*d*d) - (72 * a*c*e);
	double p = (8*a*c - 3 *b*b) / (8*a*a);
	double q = (b*b*b - 4*a*b*c + 8*a*a*d) / (8*a*a*a);
	double Q = cbrt(delta1 + sqrt(delta1*delta1 - (4*delta0*delta0*delta0))/2.0);
	double S = 0.5 * sqrt( (-2/3)*p + (1/3*a)*(Q + delta0 / Q) );

	double disc1 = -4*S*S - 2*p + q/S;
	double disc2 = -4*S*S - 2*p - q/S;
	double x1 = 1.0, x2 = 1.0, x3 = 1.0, x4 = 1.0;
	if (disc1 >= 0){
		x1 = -b/(4*a) - S + 0.5 * sqrt(disc1);
		x2 = -b/(4*a) - S - 0.5 * sqrt(disc1);
	}

	if (disc2 >= 0){
		x3 = -b/(4*a) + S + 0.5 * sqrt(disc2);
		x4 = -b/(4*a) + S - 0.5 * sqrt(disc2);
	}

	cout << "x1 = " << x1 << " " << f(x1) << endl;
	cout << "x2 = " << x2 << f(x2) << endl;
	cout << "x3 = " << x3 << f(x3) << endl;
	cout << "x4 = " << x4 << f(x4) << endl;

	return 0.0;
}

int main(){
	cout << fixed << setprecision(7);
	long double lo, hi, ans1;
	int n;
	
	// assume g <= h

	cin >> n;

	while (n--){
		cin >> w >> g >> h >> r;
		if (g > h)
			swap(g, h);
		ans1 = hypot(w, h-g);


		long double low = 0.0, hi = w;
		long double x;

		x = low;
		int it = 0;
		while (low <= hi){
			x = (low + hi) / 2.0;
			if (fp(x) < eps){
				// ??
				hi = x;
			}
			else{
				// ??
				low = x;
			}
			it++;
		}

		long double ans2 = hypot(g,x) + hypot(h, w-x);


		double ans2;
		solve(1.0, -2*w, (w*w - 1), 0.0, (h+g-2*r)*(h-g));
		cout << ans1 << " " << ans2  << endl;

	}

	return 0;
}
