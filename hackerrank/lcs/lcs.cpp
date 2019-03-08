#include <iostream>

using namespace std;

void solve(int a[], int n, int b[], int m){
	int dp[n+1][m+1];
	for (int i = 0; i <= n; ++i){
		for (int j = 0; j <= m; ++j){
			if (i == 0 or j == 0){
				dp[i][j] = 0;
			}
			else if (a[i-1] == b[j-1]){
				dp[i][j] = 1 + dp[i-1][j-1];
			}
			else{
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}

	int i = n, j = m;
	int k = dp[n][m];
	int lcs[k];
	while (i and j){
		if (a[i-1] == b[j-1]){
			lcs[k-1] = a[i-1];
			i--;
			j--;
			k--;
		}
		else if (dp[i-1][j] > dp[i][j-1]){
			i--;
		}
		else{
			j--;
		}
	}

	for (int i =0 ; i < dp[n][m]; ++i){
		cout << lcs[i] << " ";
	}
	cout << endl;

}

int main(){
	int n, m;
	cin >> n >> m;

	int a[n], b[m];

	for (int i =0 ; i < n; ++i){
		cin >> a[i];
	}

	for (int i =0 ; i < m; ++i){
		cin >> 	b[i];
	}

	solve(a, n, b, m);

	return 0;
}
