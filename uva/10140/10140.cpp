#include <iostream>
#include <vector>
using namespace std;

#define MAXN 1000000

bool isprime[MAXN];

void solve(int l, int u){
	
	vector<int> primes;
	for (int p = l; p <= u; ++p){
		if (isprime[p])	primes.push_back(p);
	}

	if (primes.size() < 2){
		cout << "There are no adjacent primes." << endl;
	}
	else{
		int a, b, c, d;
		int minDist = primes[1] - primes[0];
		int maxDist = primes[1] - primes[0];

		a = primes[1];
		b = primes[0];
		c = a;
		d = b;

		for (int i = 1; i < primes.size()-1; ++i){
			if (primes[i+1] - primes[i] < minDist){
				minDist = primes[i+1] - primes[i];
				a = primes[i+1];
				b = primes[i];
			}
			if (primes[i+1] - primes[i] > maxDist){
				maxDist = primes[i+1] - primes[i];
				c = primes[i+1];
				d = primes[i];
			}
		}

		cout << b << "," << a << " are closest, ";
		cout << d << "," << c << " are most distant." << endl;

	}

}

int main(){

	// prime sieve

	isprime[0] = false;
	isprime[1] = false;

	for (int i = 2; i < MAXN; ++i){
		isprime[i] = true;
	}

	for (int d = 2; d < MAXN; ++d){
		if (isprime[d]){
			int i = 2;
			while (i*d < MAXN){
				isprime[i*d] = false;
				i++;
			}
		}
	}

	int l, u;
	while (cin >> l >> u){
		solve(l, u);
	}

	return 0;
}
