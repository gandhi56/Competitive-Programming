#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main(){
	cout << fixed << setprecision(8);

	double l = pow(2, -3.0/4);
	double w = pow(2, -5.0/4);
	int n;
	cin >> n;

	double ans = 0.0;
	int j = 1;

	for (int i = 2; i <= n; ++i){
		j <<= 1;

		int q;
		cin >> q;

		double per = 2*(l+w);
		if (q >= j){
			ans += j * per;
			j = 0;
		}
		else{
			ans += q * per;
			j -= q;
		}

		double tmp = w;
		w = l / 2.0;
		l = tmp;
	}

	if (j == 0){
		double sol = (ans - 2*(pow(2, -1.0/4) + pow(2, -3.0/4)))/2;
		cout << sol << endl;
	}
	else{
		cout << "impossible" << endl;
	}

	return 0;
}
