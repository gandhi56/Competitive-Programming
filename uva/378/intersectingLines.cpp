
/* UVa problem: 378
 * Topic: Geometry
 *
 * Level: easy
 * 
 * Brief problem description: 
 *		Given two lines specified by two points they pass
 	through, determine if the two lines intersect, coincide
 	or run in parallel.
 *
 * Solution Summary:
 		Let L1 and L2 be lines specified by points a, b and c,d, 
 		respectively. Then the two lines intersect iff
 		cross(b-a, d-c) > 0 (upto eps). If so, compute the
 		intersection point using Cramer's rule.

 		Otherwise, the lines either coincide or run in parallel.
 		The lines coincide iff cross(b-a, b-c) > 0 (upto eps).
 *
 * Used Resources:
 *		UAlberta Programming Club Code archive
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
#include <iomanip>
using namespace std;

#define eps 1e-2

typedef complex<double> point;

double cross(point a, point b){	return imag(conj(a) * b);	}

int intersect(point a, point b, point c, point d, point& p){
	
	if (abs(cross(b-a, d-c)) > eps){
		p = cross(c-a, d-c) / cross(b-a, d-c)*(b-a) + a;
		return 1;
	}
	if (abs(cross(b-a, b-c)) > eps)	return 0;
	return -1;
}

int main(){
	int n;
	cin >> n;

	cout << "INTERSECTING LINES OUTPUT" << endl;

	cout << fixed << setprecision(2);

	while (n--){
		int a, b, c, d, e, f, g, h;
		cin >> a >> b >> c  >> d >> e >> f >> g  >> h;

		point p1(a, b);
		point p2(c, d);
		point p3(e, f);
		point p4(g, h);
		point p;
		int k = intersect(p1, p2, p3, p4, p);
		if (k == -1){
			cout << "LINE" << endl;
		}
		else if (k == 0){
			cout << "NONE" << endl;
		}
		else{
			cout << "POINT " << p.real() << " " << p.imag() << endl;
		}
	}

	cout << "END OF OUTPUT" << endl;
	return 0;
}
