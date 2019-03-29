#include <iostream>
#include <bitset>
using namespace std;

int m;

bool isprime(int p){
	for (int d = 2; d*d <= p; ++d){
		if (p%d == 0)	return false;
	}
	return true;
}

int solve(int n, string p){
	if (n == m)		return -1;
	if (m > n)		return 0;

}

int main(){

	int t;
	cin >> t;

	while (t--){
		int n;
		string play;
		cin >> n >> play;

		m = 1;

		int val = solve(n, play);
	}

	return 0;
}
