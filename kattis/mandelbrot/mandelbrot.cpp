#include <iostream>
#include <complex>

using namespace std;

int main(){
	double x, y;
	int r;
	int t = 1;
	while (cin >> x >> y >> r){
		complex<double> c(x, y);
		complex<double> z(0,0);
		while (r--){
			z = z*z + c;
		}

		if (abs(z) > 2.0){
			cout << "Case " << t << ": OUT" << endl;
		}
		else{
			cout << "Case " << t << ": IN" << endl;
		}
		t++;
	}

	return 0;
}
