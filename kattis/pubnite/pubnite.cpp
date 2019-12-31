#include <bits/stdc++.h>
#define EPS 1e-6
using namespace std;

typedef long double ld;

ld sq(ld x){
	return x*x;
}

ld xs, ys, ss, ri, rf;
ld xa, ya, sa;

ld rad(){
	return sqrt( sq(xa - xs) + sq(ya - ys) );
}

bool is_safe(ld x, ld y, ld r){
	return (sq(x - xs) + sq(y - ys)) <= sq(r);
}

int main(){
	cin >> xs >> ys >> ss >> ri >> rf;
	cin >> xa >> ya >> sa;

	cout.setf(ios::fixed);
	cout.precision(8);

	if (is_safe(xa, ya, ri)){
		if (ss > sa){
			// Anthony is in circle initally, but runs slower than the radius
			// Anthony can get out of the circle after t sec.
			// circle keeps shrinking, Anthony keeps running;
			// circle stops shrinking after rt sec. --> Anthony is unsafe
			// Anthony keeps running until he reaches rf
			// 0 - t : safe
			// t - rt : unsafe
			// time until Anthony reaches rf
			//cout << "1" << endl;
			ld ai = rad();
			ld t = (ri - ai) / (ss - sa);	// time when circle surpasses anthony
			ld rt = (ri - rf) / ss;	// time until circle stops shrinking
			ld ap = ai - sa*rt;	// Anthony's position after rt sec.
			ld at = 0.0;
			if (ap > rf){
				at = (ap - rf) / sa;
				cout << rt - t + at << endl;
			}
			else{
				cout << 0.0 << endl;
			}
    }
		else{
			// No damage, Anthony is always safe
			//cout << "2" << endl;
			cout << 0.0 << endl;
		}
	}
	else{
    // Anthony is outside of the safe zone
		if (ss >= sa){
			// this is good now!
			ld rt = (ri - rf) / ss;
			ld ai = rad();
			ld ap = ai - sa*rt;	// Anthony's position after rt sec.
			ld at = (ap - rf) / sa;
			cout << rt + at << endl;
		}
		else{
			// Anthony faster than the circle
			ld ai = rad();
			ld t = (ri - ai) / (ss - sa); // when Anthony reaches safe zone
			ld rt = (ri - rf) / ss;
			if (t <= rt){
				cout << t << endl;
			}
			else{
				// this is good now!
				ld ap = ai - sa*rt;
				ld at = (ap - rf) / sa;
				cout << rt + at << endl;
			}
		}
	}

	return 0;
}
