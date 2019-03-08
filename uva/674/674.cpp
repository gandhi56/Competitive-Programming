#include <iostream>
#include <string.h>
using namespace std;

unsigned long solve(unsigned long* coins, unsigned long numCoins, unsigned long value){
	unsigned long dp[value+1];
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;

	for (unsigned int i = 0; i < numCoins; ++i){
		for (unsigned int j = coins[i]; j <= value; ++j){
			dp[j] += dp[j - coins[i]];
		}
	}

	return dp[value];
}

int main(){

	unsigned long coins[] = {50, 25, 10, 5, 1};
	unsigned long n;
	while (cin >> n){
		cout << solve(coins, 5, n) << endl;
	}

	return 0;
}

