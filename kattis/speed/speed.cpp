#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	int n; 
	double t = 0.0;
	cin >> n >> t;

	double d[n];
	double s[n];

	double lo = 100000000.0;
	double hi = 1001000.0;
	
	for (int i = 0; i < n; ++i){
		cin >> d[i] >> s[i];
		lo = min(lo, s[i]);
	}

	lo = -lo;

	double mid;
	while (hi-lo > 0.000000001){
		mid = (lo+hi)/2.0;
		double sum = 0.0;
		for (int i = 0; i < n; ++i){
			sum += d[i] / (s[i] + mid);
		}

		if (sum > t){
			lo = mid;
		}
		else if (sum < t){
			hi = mid;
		}
		else{
			break;
		}
	}

	cout << fixed << setprecision(10);
	cout << mid << endl;

	return 0;
}
