/* UVa problem: 11068
 
 * Topic: Geometry
 *
 * Level: easy
 * 
 * Brief problem description: 
 *		Given two lines per test case, in the form of Ax + By = C in R^2, 
 	determine if a fixed point exists when the plane is mirrored
 	at both lines sequentially.
 *
 * Solution Summary:
 *		Use basic geometry and manipulationsof line equations.
 *
 * Used Resources:
 *		None
 *
 * I hereby certify that I have produced the following solution myself
 * using only the resources listed above in accordance with the CMPUT
 * 403 collaboration policy.
 *
 *
 * --------------------- Anshil Gandhi
 */


#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	int a, b, c;
	int p, q, r;

	cout << fixed << setprecision(2);

	while (cin >> a >> b >> c >> p >> q >> r){
		if (!a and !b and !c and !p and !q and !r)	break;
		int denom = a*q - b*p;
		if (denom){
			double x, y;
			x = c*q - b*r;
			if (x)	x /= denom;
			y = a*r - c*p;
			if (y)	y /= denom;
			cout << "The fixed point is at " << x << " " << y << "." << endl;
		}
		else{
			cout << "No fixed point exists." << endl;
		}
	}

	return 0;
}
