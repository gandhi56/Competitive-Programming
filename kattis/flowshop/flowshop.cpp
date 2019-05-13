#include <iostream>
#include <cstring>
using namespace std;

typedef unsigned long long ull;

ull p[1001][1001];
ull dp[1001][1001];
int n, m;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < m; ++j){
			cin >> p[i][j];
		}
	}

	dp[0][0] = p[0][0];
	for (int i = 1; i < m; ++i){
		dp[0][i] = dp[0][i-1] + p[0][i];
	}

	for (int i = 1; i < n; ++i){
		dp[i][0] = dp[i-1][0] + p[i][0];
		for (int j = 1; j < m; ++j){
			dp[i][j] = p[i][j] + max(dp[i-1][j], dp[i][j-1]);
		}
	}

	for (int i = 0; i < n; ++i){
		cout << dp[i][m-1] << " ";
	}
	cout << endl;

	return 0;
}
