#include <iostream>
using namespace std;

int solve(int a[], int n){
	int lis[n];
	int lds[n];
	for (int i = 0; i < n; ++i){
		lis[i] = 1;
		lds[i] = 1;
	}

	for (int i = 1; i < n; ++i){
		for (int j = 0; j < i; ++j){
			if (a[i] > a[j] and lis[i] < lis[j] + 1){
				lis[i] = lis[j] + 1;
			}
		}
	}

	for (int i = n - 2; i >= 0; --i){
		for (int j = n - 1; j > i; --j){
			if (a[i] > a[j] and lds[i] < lds[j] + 1){
				lds[i] = lds[j] + 1;
			}
		}
	}

	int ans = lis[0] + lds[0] - 1;
	for (int i = 1; i < n; ++i){
		ans = max(lis[i] + lds[i] - 1, ans);
	}

	return ans;
}

int main(){
	int t;
	cin >> t;

	while (t--){
		int n;
		cin >> n;

		int a[n];
		for (int i =0 ; i < n; ++i)	cin >> a[i];

		cout << solve(a, n) << endl;
	}

	return 0;
}
