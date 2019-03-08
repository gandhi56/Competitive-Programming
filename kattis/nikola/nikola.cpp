#include <iostream>
#include <cstring>
#include <climits>
#include <cmath>
using namespace std;

int entryFee[1010];
int n;
int dp[1010][1010];
int solve(int i, int j, int cost){
	if (i < 1 or i > n)	return INT_MAX;
	
	if (dp[i][j] != 0)	return dp[i][j];
	
	if (i == 1 and j == 0)	{	
		dp[i][j] = solve(2, 1, entryFee[2]);
	}
	else if (i == n){	
		dp[i][j] = cost;
	}
	else{
		dp[i][j] = INT_MAX;
		if (i+j+1 <= n){
			dp[i][j] = solve(i+j+1, j+1, cost + entryFee[i+j+1]);
		}

		if (i-j >= 1){
			dp[i][j] = min(dp[i][j], solve(i-j, j, cost+entryFee[i-j]));
		}
	}
	return dp[i][j];
}

int solve(){
	for (int i = n; i >= 1; --i){
		for (int j = n; j >= 0; --j){
			dp[i][j] = (int)INFINITY;
			if (i == 1 and j == 0){
				dp[i][j] = dp[2][2] + entryFee[2];
			}
			else if (i == n){
				dp[i][j] = entryFee[n];
			}
			else{
				if (i+j+1 <= n){
					dp[i][j] = dp[i+j+1][j+1] + entryFee[i+j+1];
				}
				if (i-j >= 1){
					dp[i][j] = min(dp[i][j], dp[i-j][j] + entryFee[i-j]);
				}
			}
		}
	}
	return dp[1][0];
}

int main(){
	cin >> n;

	memset(dp, 0, sizeof(dp));

	for (int i = 1; i <= n; ++i){
		cin >> entryFee[i];
	}

	cout << solve() << endl;

	return 0;
}
