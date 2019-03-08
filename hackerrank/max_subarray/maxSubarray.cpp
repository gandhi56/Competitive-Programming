#include <iostream>

using namespace std;

int maxSubsequence(int arr[], int n){
	int dp[n];
	dp[0] = arr[0];
	for (int i = 1; i < n; ++i){
		dp[i] = arr[i];
		dp[i] = max(dp[i], max(dp[i-1], dp[i-1] + arr[i]));
	}

	return dp[n-1];
}

int maxSubarray(int arr[], int n){
	int end = arr[0];
	int sofar = arr[0];
	for (int i = 1; i < n; ++i){
		end = max(arr[i], end + arr[i]);
		sofar = max(sofar, end);
	}

	return sofar;
}

int main(){
	int t;
	cin >> t;

	while (t--){
		int n;
		cin >> n;

		int arr[n];
		for (int i = 0; i < n; ++i){
			cin >> arr[i];
		}

		cout << maxSubarray(arr, n) << " " << maxSubsequence(arr, n) << endl;
	}

	return 0;
}
