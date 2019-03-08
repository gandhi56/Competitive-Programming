#include <initializer_list>
#include <cstdint>
#include <iostream>

using namespace std;
using u128 = __uint128_t;
using ll = long long;


int triples[1000001];
int p[1000001];

u128 powmod(u128 b, u128 e, u128 m){
	u128 res = 1;
	for (b %= m; e; e >>= 1){
		if (e&1)	res = res*b%m;
		b = b * b%m;
	}

	return res;
}

bool isprime(uint64_t n){
	if (n < 2)	return false;
	u128 d = n-1, r = 0;
	while (d%2 == 0)	r++, d /= 2;
	for (u128 a : {2,3,5,7,11,13,17,19,23,29,31,37}){
		if (a > n - 2)	break;
		u128 x = powmod(a, d, n);
		if (x == 1 or x == n-1)	continue;
		for (u128 j = 0; r and j < r - 1; j++){
			x = x*x%n;
			if (x == n - 1)	goto next;
		}
		return false;
	next:	;
	}
	return true;
}

bool goodTriplet(ll a, ll b, ll c){
	return a*a + b*b == c*c;
}

void compute(int n){
	
}

int main(){
	for (int i = 0; i <= 1e6; ++i) triples[i] = -1, p[i] = 0;

	int n;
	while (cin >> n){
		if (count[n] == -1){
			compute(n);
		}
	}
	return 0;
}
