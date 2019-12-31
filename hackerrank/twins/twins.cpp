#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
using namespace std;

typedef unsigned long long ull;

void count_twins(ull n, ull m){
	vector<bool> isprime(true, m+1);
	isprime[0] = false;
	isprime[1] = false;

	for (ull i = 2; i*i <= m; ++i){
		if (isprime[i]){
			ull j = 2*i;
			while (j <= m){
				isprime[j] = false;
				j += i;
			}
		}
	}
	ull count = 0;
	for (ull i = n; i <= m-2; ++i){
		if (isprime[i] && isprime[i+2]){
			count++;
		}
	}

	cout << count << endl;

}

void simple_sieve(ull limit, vector<ull>& primes){
	bool mark[limit + 1];
	memset(mark, true, sizeof(mark));
	for (ull p = 2; p*p < limit; ++p){
		if (mark[p]){
			for (ull i = p*2; i < limit; i += p){
				mark[i] = false;
			}
		}
	}

	for (ull p = 2; p < limit; ++p){
		if (mark[p])	primes.push_back(p);
	}

}

void segmented_sieve(ull n){
	ull limit = floor(sqrt(n)) + 1;
	vector<ull> primes;
	simple_sieve(limit, primes);
	ull lo = limit;
	ull hi = 2 * limit;

	while (lo < n){
		if (hi >= n)	hi = n;
		bool mark[limit + 1];
		memset(mark, true, sizeof(mark));

		for (ull i = 0; i < primes.size(); ++i){
			ull loLim = floor(lo/primes[i]) * primes[i];
			if (loLim < lo){
				loLim += primes[i];
			}

			for (ull j = loLim; j < hi; j += primes[i]){
				mark[j - lo] = false;
			}
		}

		/*
		for (ull i = lo; i < hi; ++i){
			if (mark[i - lo])
				cout << i << " ";
		}
		*/

		lo += limit;
		hi += limit;

	}
	cout << endl;
}

int main(){
	ull n, m;
	cin >> n >> m;
	count_twins(n, m);

//	vector<ull> primes;
//	simple_sieve(1e9, primes);

	//segmented_sieve(1e9);

	return 0;
}

