#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

#define eps 	1e-4

int w, g, h, r;

inline long double sq(long double x){
	return x*x;
}

int main(){
	cout << fixed << setprecision(6);
	long double lo, hi;
	int n;
	
	// assume g <= h

	cin >> n;

	while (n--){
		cin >> w >> g >> h >> r;
		if (g > h)
			swap(g, h);
		lo = sqrt(sq(w) + sq(h-g));
		long double x = (w * (g - r)) / (g + h - 2.0*r);
		long double l1 = (long double)sqrt( (long double)sq(x) + (long double)sq(g-r) );
		long double l2 = (long double)sqrt( (long double)sq(w-x) + (long double)sq(h-r) );
		cout << lo << " " << l1 + l2 << endl;

	}

	return 0;
}
