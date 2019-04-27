#include <iostream>
#include <cmath>
using namespace std;

const int INF = 1e8;

int cap;
int n;
int w[2002];
int v[2002];
int dp[2002][2002];

int solve(int i, int j){
	if (i == n)	return j >= 0 ? 0 : -INF;
	if (j < 0)	return -INF;
	if (dp[i][j] != -1)	return dp[i][j];
	return dp[i][j] = max(solve(i+1, j), solve(i+1, j-w[i]) + v[i]);
}

int main(){
	while (cin >> cap >> n){
		for (int i = 0; i < n; ++i){
			cin >> v[i] >> w[i];
		}

		cout << solve(0, cap) << endl;
	}

	return 0;
}
