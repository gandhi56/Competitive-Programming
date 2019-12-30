#include <iostream>
using namespace std;

#define MAXN 1010
#define MAXW 40

int knapsack(int weight, int p[], int w[], int n){
	int dp[MAXN][MAXW];

	for (int i = 0; i <= n; ++i){
		for (int j = 0; j <= weight; ++j){
			if (i == 0 or j == 0){
				dp[i][j] = 0;
			}
			else if (w[i-1] <= j){
				dp[i][j] = max(p[i-1] + dp[i-1][j - w[i-1]], dp[i-1][j]);
			}
			else{
				dp[i][j] = dp[i-1][j];
			}
		}
	}

	return dp[n][weight];
}

int main(){
	int t;
	cin >> t;

	while (t--){
		int n;
		cin >> n;

		int p[n], w[n];
		for (int i =0 ; i < n; ++i){
			cin >> p[i] >> w[i];
		}

		int ans = 0;
		int g;
		cin >> g;

		while (g--){
			int maxWeight;
			cin >> maxWeight;
			ans += knapsack(maxWeight, p, w, n);
		}

		cout << ans << endl;
	}

	return 0;
}
