#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int n, k;
	cin >> n >> k;

	int a[n];
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	sort(a, a+n);
	int t =0 ;
	for (int i = n-1; i > n-1-k; --i)
		t += a[i];

	cout << t << endl;
	return 0;
}
