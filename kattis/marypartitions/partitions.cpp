#include <iostream>
#include <map>
using namespace std;


int solve(int m, int n, int p, map< pair<int,int>,int >& dp){
	if (n == 0)	return 1;
	if (p <= 0)	return 0;
	if (p == 1)	return 1;

	pair<int,int> k = {n, p};

	if (dp.count(k))	return dp[k];

	int count = 0;
	if (n >= p)	count = solve(m, n-p, p, dp);
	if (p >= 1)	count += solve(m, n, p/m, dp);
	return dp[k] = count;
}

int main(){
	int t;
	cin >> t;

	while (t--){
		int k, m, n;
		cin >> k >> m >> n;

		map< pair<int,int>, int > dp;

		int p = m;
		while (p <= n){
			p *= m;
		}

		cout << k << " " << solve(m, n, p, dp) << endl;
	}

	return 0;
}
