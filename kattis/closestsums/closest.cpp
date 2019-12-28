#include <iostream>
#include <climits>
using namespace std;

void solve(int arr[], int n, int num){
	int minDiff = INT_MAX;
	int ans;
	for (int i = 0; i < n; ++i){
		for (int j = i + 1; j < n; ++j){
		
			int sum = arr[i] + arr[j];
			if (abs(sum-num) < minDiff){
				minDiff = abs(sum - num);
				ans = sum;
			}

		}	
	}

	cout << "Closest sum to " << num << " is " << ans << "." << endl;
}

int main(){
	int n;
	int t = 1;
	while (cin >> n){
		int arr[n];
		for (int i =0 ; i < n; ++i)	cin >> arr[i];

		int q;
		cin >> q;

		cout << "Case " << t << ":" << endl;

		while (q--){
			int num;
			cin >> num;
			solve(arr, n, num);
		}
		t++;
	}

	return 0;
}
