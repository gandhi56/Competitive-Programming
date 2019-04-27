#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
typedef unsigned long long ll;

int main(){
	cout << fixed << setprecision(7);

	int t;
	cin >> t;

	while (t--){
		int n;
		cin >> n;
		
		ll cust[n];
		for (int i = 0; i < n; ++i){
			cust[i] = 0;
			
			int w;
			cin >> w;
			while (w--){
				ll x;
				cin >> x;
				cust[i] += x;
			}
		}

		sort(cust, cust+n);

		double ans = 0;
		for (int i = 0; i < n; ++i)	ans += cust[i]*(n-i);
		cout << (double)(ans/n) << endl;

	}

	return 0;
}
