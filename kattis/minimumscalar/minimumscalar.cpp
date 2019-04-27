#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int t;
	cin >> t;

	for (int i = 1; i <= t; ++i){
		int n;
		cin >> n;

		unsigned long long a[n], b[n];
		for (int k = 0; k < n; ++k)	cin >> a[k];
		for (int k = 0; k < n; ++k)	cin >> b[k];

		sort(a, a+n);
		sort(b, b+n);

		unsigned long long val = 0;
		for (int k = 0; k < n; ++k)	val += a[k] * b[n-k-1];
		cout << "Case #" << i << ": " << val << endl;
	}

	return 0;
}
