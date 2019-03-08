#include <iostream>
using namespace std;

int max(int a, int b){	return (a > b)?a : b;}

void knapsack(int cap, int v[], int w[], int n){
	int dp[n+1][cap+1];

	for (int i = 0; i <= cap; ++i)	dp[0][i] = 0;

	for (int i = 1; i <= n; ++i){
		for (int j = 0; j <= cap; ++j){
			if (i == 0 or j == 0){
				dp[i][j] = 0;
			}
			else if (w[i-1] <= j){
				dp[i][j] = max(dp[i-1][j], v[i-1]+dp[i-1][j-w[i-1]]);
			}
			else{
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	cout << dp[n][cap] << endl;
}

int main(){
	double C;
	int n;
	while (cin >> C >> n){
		int cap = C;
		int value[n], weight[n];
		for (int i =0 ; i < n; ++i){
			cin >> value[i] >> weight[i];
		}
		knapsack(cap, value, weight, n);
	}

	return 0;
}
