#include <bits/stdc++.h>
#define EPS 1e-6

using namespace std;
long double sq(long double x){
	return x*x;
}

int main(){
	long double xs, ys, ss, ri, rf;
	cin >> xs >> ys >> ss >> ri >> rf;

	long double xa, ya, sa;
	cin >> xa >> ya >> sa;

	long double theta = (long double)atan(fabs(ya-ys)/fabs(xa-xs));
	long double dx = sa * (long double)cos(theta);
	long double dy = sa * (long double)sin(theta);

	long double d = 0.0;
	while (rf + EPS < ri){
		if (sq(ri) + EPS < sq(xa - xs) + sq(ya - ys))	d += 1.0;
		xa += dx;
		ya += dy;
		ri -= ss;
	}

	cout.setf(ios::fixed);
	cout.precision(8);
	cout << d << endl;

	return 0;
}
