#include <iostream>
using namespace std;

typedef unsigned long long ull;

ull f(ull n, ull m){
	ull dp[n+2];
	dp[0] = 0;
	dp[1] = 1;
	for (ull i = 2; i < n+1; ++i){
		dp[i] = (dp[i-1] + dp[i-2]) % (1<<m);
	}

	return dp[n];
}

int main(){
	ull n, m;

	while (cin >> n >> m){
		cout << f(n, m) << endl;
	}

	return 0;
}
