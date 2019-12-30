#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

const int inf = 1e9;

void solve(int arr[], int n){
	int d[n+1];
	int p[n+1];
	int m[n+1];
	int s[n+1];
	vector<int> ind;
	for (int i = 0 ; i < n+1; ++i)	d[i] = inf;
	d[0] = -inf;
	for (int i = 0; i < n; ++i){
		int j = upper_bound(d, d+(n+1), arr[i]) - d;
		if (d[j-1] < arr[i] and arr[i] < d[j]){
			d[j] = arr[i];
			ind.push_back(j);
		}
	}

	int ans = 0;
	for (int i =0 ; i <= n; ++i){
		if (d[i] < inf){
			ans = i;
		}
	}
	cout << ans << endl;
	
	for (int v : ind){
		cout << v << " ";
	}
	
	cout << endl;
}

int main(){
	int n;
	while (cin >> n){
		int arr[n];
		for (int i =0 ; i < n; ++i){
			cin >> arr[i];
		}
		solve(arr, n);
	}

	return 0;
}
