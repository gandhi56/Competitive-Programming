#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

void solve(long n){
	// find all proper divisors of n
	vector<long> divisors;
	for (long d = 1; d*d <= n; ++d){
		if (n%d == 0 and d != n){
			divisors.push_back(d);
			if (n/d != d and d != 1)	divisors.push_back(n/d);
		}
	}

	int count =0;
	for (auto d : divisors){
		if (d%2 == 0){
			long double sr = sqrt(d);
			if (sr - floor(sr) == 0){
				count++;
			}
		}
	}

	int p = count;
	int q = divisors.size();
	int gcd = __gcd(p, q);
	if (p == 0)	cout << "0" << endl;
	else		cout << p/gcd << "/" << q/gcd << endl;
}

int main(){
	int t;
	cin >> t;

	while (t--){
		long n;
		cin >> n;
		solve(n);
	}

	return 0;
}
