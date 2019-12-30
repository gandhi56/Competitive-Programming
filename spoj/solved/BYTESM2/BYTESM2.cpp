#include <iostream>
using namespace std;

int in[102][102];
int dp[102][102];
int h, w;
int solve(int i, int j){
	if (dp[i][j] != -1)	return dp[i][j];
	if (i == h-1){
		dp[i][j] = in[i][j];
	}
	else{
		int a = -1;
		int b = solve(i+1, j);
		int c = -1;
		if (j-1 >= 0)	a = solve(i+1, j-1);
		if (j+1 < w)	c = solve(i+1, j+1);
		dp[i][j] = in[i][j] + max(a, max(b, c));
	}
	return dp[i][j];
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int t;
	cin >> t;
	while (t--){
		cin >> h >> w;
		for (int i = 0; i < h; ++i){
			for (int j = 0; j < w; ++j){
				cin >> in[i][j];
				dp[i][j] = -1;
			}
		}

		int best = 0;
		for (int i = 0; i < w; ++i){
			best = max(best, solve(0, i));
		}
		cout << best << endl;

	}

	return 0;
}
