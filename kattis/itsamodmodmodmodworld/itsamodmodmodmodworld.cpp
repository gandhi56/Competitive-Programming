#include <iostream>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;

ull sum_of_floors(ull p, ull q, ull n){
	if (p == 0 or n == 0)	return 0;

	if (n >= q){
		return p*(n/q)*(n+1) - 
				(n/q)*((n/q)*p*q + p + q - 1)/2+
				sum_of_floors(p, q, n%q);
	}

	if (p >= q){
		return (p/q)*n*(n+1)/2 + sum_of_floors(p%q, q, n);
	}

	return (n*p/q)*n-sum_of_floors(q,p,n*p/q);
}

int main(){
	int c;
	cin >> c;

	while (c--){
		ull p, q, n;
		cin >> p >> q >> n;
		ull g = __gcd(p, q);
		cout << (p*n*(n+1)/2) - q * sum_of_floors(p/g, q/g, n) << endl;
	}

	return 0;
}
