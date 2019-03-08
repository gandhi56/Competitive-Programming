#include <iostream>
#include <string.h>
#include <iomanip>
using namespace std;

unsigned long long dp[40000];

unsigned long long solve(int coins[], int numCoins, unsigned long long value){
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;

	for (unsigned long i = 0; i < numCoins; ++i){
		for (unsigned long j = coins[i]; j <= value; ++j){
			dp[j] += dp[j - coins[i]];
		}
	}

	return dp[value];
}

int main(){
	int coins[] = {10000,5000,2000,1000,500,200,100,50,20,10,5};
	int n = 11;
	double amount;

	while (cin >> amount){
		if (amount == 0.00)	break;
		cout << right << setw(6) << fixed << setprecision(2) << amount;
		cout << right << setw(17) << solve(coins, n, (int)(amount*100)) << endl;
	}
	return 0;
}

