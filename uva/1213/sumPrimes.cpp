/* UVa problem: 1213 - Sum of Different Primes
 *
 * Topic: Dynamic Programming
 *
 * Level: easy
 * 
 * Brief problem description: 
 *		Given positive integers n and k, output the number of ways
 		n can be expressed as a sum of k primes.
 *
 * Solution Summary:
 *		dp[i][j] = number of ways to express i as a sum of j primes
 *
 * Used Resources:
 *		None
 *
 * I hereby certify that I have produced the following solution myself
 * using only the resources listed above in accordance with the CMPUT
 * 403 collaboration policy.
 *
 *
 * --------------------- Anshil Gandhi
 */



#include <iostream>
#include <bitset>
#include <cstring>
using namespace std;

bitset<2000> isprime;

int solve(int n, int k){
	int dp[n+1][k+1];
	memset(dp, 0, sizeof(dp));

	for (int i = 0; i <= n; ++i){
		for (int j = 0; j <= k; ++j){
			if (i == 0 or j == 0){
				dp[i][j] = 0;
			}
			else if (isprime[i] and j == 1){
				dp[i][j] = 1;
			}
			else{
				for (int p = 2; p <= i-2; ++p){
					if (isprime[p]){
						dp[i][j] += (dp[p][1] + dp[i-p][j-1]);
					}
				}
			}
		}
	}
	return dp[n][k];
}

int main(){

	// find all primes upto 1999
	isprime.set();
	isprime.set(0,0);
	isprime.set(1,0);
	for (int p = 2; p*p < 2000; ++p){
		if (isprime[p]){
			for (int d = p*p; d < 2000; d += p){
				isprime.set(d, 0);
			}
		}
	}

	int n, k;
	while (cin >> n >> k){
		if (n == 0 and k == 0)	break;
		cout << solve(n, k) << endl;
	}

	return 0;
}
