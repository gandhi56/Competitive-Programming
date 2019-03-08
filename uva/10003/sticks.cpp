#include <iostream>
#include <climits>
using namespace std;

int l;
int n;
int dp[52][52];
int c[52];

int cut(int lo, int hi){
	if (lo-hi == -1)	return 0;
	if (dp[lo][hi] != -1)	return dp[lo][hi];
	int best = 100000;
	for (int i = lo+1; i < hi; ++i){
		best = min(best, cut(lo,i) + cut(i, hi) + c[hi]-c[lo]);
	}

	return dp[lo][hi] = best;
}

int main(){
	while (cin >> l){
		if (l == 0)	break;

		for (int i = 0; i < 52; ++i){
			for (int j = 0; j < 52; ++j){
				dp[i][j] = -1;
			}
		}

		cin >> n;

		for (int i =1 ; i <= n; ++i)	cin >> c[i];
		c[n+1] = l;
		cout << "The minimum cutting is " << cut(0,n+1) << "." << endl;

	}
	return 0;
}
