#include <iostream>
using namespace std;

int solve(int c[], int n){
	int maxend = c[0];
	int maxsofar = c[0];

	for (int i = 1; i < n; ++i){
		maxend = max(c[i], maxend + c[i]);
		maxsofar = max(maxsofar, maxend);
	}

	return maxsofar;
}

int main(){
	int n, p;
	cin >> n >> p;

	int count[n];
	for (int i =0; i < n; ++i){
		cin >> count[i];
		count[i] -= p;
	}

	cout << solve(count, n) << endl;

	return 0;
}
