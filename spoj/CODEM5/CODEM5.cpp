#include <iostream>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;

const int M = 5025;
int dp[5025];

int main(){
	int t;
	cin >> t;

	while (t--){
		int n, k;
		cin >> n >> k;
		int a[n];
		for (int i =0 ; i < n; ++i)	cin >> a[i];
		fill(dp+1, dp+M, 99999);
		for (int i = 0; i < n; ++i){
			for (int j = k - a[i]; j >= 0; --j){
				dp[j+a[i]] = min(dp[j+a[i]], dp[j]+1);
			}
		}

		if (dp[k] == 99999){
			cout << "impossble" << endl;
		}
		else{
			cout << dp[k] << endl;
		}
	}
	return 0;
}
