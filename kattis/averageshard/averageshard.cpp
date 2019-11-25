#include <iostream>
using namespace std;
int main(){
	int t;
	cin >> t;

	while (t--){
		int n, e;
		cin >> n >> e;

		int iq[n];
		double csAve = 0.0;
		double eAve = 0.0;
		for (int i = 0; i < n; ++i){
			cin >> iq[i];
			csAve += iq[i];
		}
		for (int i =0  ;i < e; ++i){
			double val;
			cin >> val;
			eAve += val;
		}
		csAve = (double)(csAve/n);
		eAve = (double)(eAve/e);

		int count = 0;
		for (int i =0 ; i < n; ++i){
			if (iq[i] < csAve and iq[i] > eAve)	count++;
		}
		cout << count << endl;

	}

	return 0;
}
