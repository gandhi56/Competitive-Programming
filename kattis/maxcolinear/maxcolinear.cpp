#include <iostream>
#include <complex>
using namespace std;

const double eps = 1E-6;
typedef complex<double> point;



int main(){
	int n;

	while (cin >> n){
		if (n == 0)	break;
		point pts[n];
		for (int i = 0; i < n; ++i){
			int x, y;
			cin >> x >> y;
			pts[i] = point(x, y);
		}


	}

	return 0;
}
