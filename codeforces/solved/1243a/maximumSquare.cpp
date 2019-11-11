#include <bits/stdc++.h>
using namespace std;

int count(int* arr, int n, int x){
	int cnt = 0;
	for (int i = n-1; i>= 0; --i){
		if (arr[i] >= x)	++cnt;
	}
	return cnt;
}

int main(){
	int k;
	cin >> k;

	while (k--){
		int n;
		cin >> n;
		int a[n];
		for (int i =0; i < n; ++i){
			cin >> a[i];
		}

		for (int i = n; i >= 0; --i){
			if (count(a, n, i) >= i){
				cout << i << endl;
				break;
			}
		}

	}
	return 0;
}
