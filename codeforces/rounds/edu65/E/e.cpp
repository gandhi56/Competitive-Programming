#include <iostream>
using namespace std;

#define MAXN 1000001

int a[MAXN];
int n, x;

int main(){
	cin >> n >> x;
	for (int i =0 ; i < n; ++i)	cin >> a[i];

	int dp[n][n];
	for (int i = 0; i < n; ++i){
		for (int j = i; j < n; ++j){
			if (i == j){
				dp[i][j] = 0;
			}
		}
	}

	return 0;
}
