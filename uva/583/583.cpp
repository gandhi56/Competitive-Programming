#include <iostream>
#include <stdio.h>
#include <map>
#include <vector>
using namespace std;

void solve(long n){

	cout << n << " = ";
	if (n < 0){
		cout << "-1 x ";
	}

	long num = n;
	map<long,long> primes;
	if (n < 0)	n *= -1;
	for (long d = 2; d*d <= n; ++d){
		while (n%d == 0){
			++primes[d];
			n /= d;
		}
	}
	if (n > 1)	++primes[n];

	map<long,long>::iterator it = primes.begin();
	while (true){
		long count = it->second - 1;
		while (true){
			cout << it->first;
			if (count)	cout << " x ";
			count--;
			if (count == -1)	break;
		}
		++it;
		if (primes.end() == it)	break;
		cout << " x ";
	}
	cout << endl;

}

int main(){
	long n;
	while (scanf("%ld", &n)){
		if (n == 0)	break;
		solve(n);
	}

	return 0;
}
