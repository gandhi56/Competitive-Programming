#include <iostream>
using namespace std;

int dp[102][502*102];

int solve(int i, int diff, int coins[], int n){
	if (i == n)	return diff;
	if (dp[i][diff] == -1){
		dp[i][diff] = min(solve(i+1, diff + coins[i], coins, n),
							solve(i+1, abs(diff - coins[i]), coins, n));
	}

	return dp[i][diff];
}

int main(){
	int t;
	cin >> t;

	while (t--){
		int n;
		cin >> n;

		int coins[n];
		for (int i = 0; i < n; ++i)	cin >> coins[i];

		for (int i = 0; i < n; ++i){
			for (int j = 0; j < 501 * n; ++j){
				dp[i][j] = -1;
			}
		}

		cout << solve(0, 0, coins, n) << endl;
	}

	return 0;
}
