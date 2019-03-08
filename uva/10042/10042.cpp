#include <iostream>
#include <map>
#include <vector>

using namespace std;

typedef unsigned long long int ull;

ull digit_sum(ull n){
	ull sum = 0;
	while (n){
		sum += (n%10);
		n /= 10;
	}

	return sum;
}

ull primes_sum(ull n){
	ull sum = 0;
	for (ull d = 2; d*d <= n; ++d){
		while (n%d == 0){
			n /= d;
			sum += d;
		}
	}
	if (n > 1)	sum += n;

	return (sum == n+1? -1 : sum);

}

bool is_smith(ull n){
	// n is a smith number if,
	// 	n is composite
	// 	digit_sum(n) = sum of all prime factors of n

	return (primes_sum(n) == digit_sum(n));
}

void solve(ull n){
	while (!is_smith(n))	n++;
	cout << n << endl;
}

int main(){
	int t;
	cin >> t;
	while (t--){
		ull n;
		cin >> n;
		solve(n);
	}

	return 0;
}
