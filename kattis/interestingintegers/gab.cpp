#include <iostream>
using namespace std;

#define MAXN 1000000
typedef long long ll;

bool gabonacci(ll a, ll b, ll num){
	ll dp[MAXN];
	dp[0] = a;
	dp[1] = b;
	for (int i = 0; i < MAXN; ++i){
		dp[i] = dp[i-1] + dp[i-2];
		if (dp[i] == num){
			return true;
		}
	}
	return false;
}

void solve(ll num){
	ll a, b;
	bool solved = false;
	for (a = 1; a <= num and !solved; ++a){
		for (b = a; b <= num and !solved; ++b){
			if (gabonacci(a, b, num)){
				cout << a << " " << b << endl;
				solved = true;
			}
		}
	}
}

int main(){
	int t;
	cin >> t;

	while (t--){
		ll num;
		cin >> num;
		solve(num);
	}

	return 0;
}
