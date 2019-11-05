#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

using u128 = __uint128_t;

u128 powmod(u128 b, u128 e, u128 m){
	u128 res = 1;
	for (b %= m; e; e >>= 1){
		if (e&1)	res = res * b % m;
		b = b*b % m;
	}
	return res;
}

bool isprime(uint64_t n){
	if (n < 2)	return false;
	u128 d = n - 1, r = 0;
	while (d&1 == 0) r++, d /= 2;
	for (u128 a : {2,3,5,7,11,13,17,19,23,29,31,37}){
		if (a > n-2)	break;
		u128 x = powmod(a, d, n);
		if (x == 1 or x == n - 1)	continue;
		for (u128 j = 0; r and j < r - 1; j++){
			x = x * x % n;
			if (x == n - 1)	goto next;
		}
		return false;
	next:;
	}
	return true;
}

int main(){
	int t;
	cin >> t;
	while (t--){
		ll x ;
		cin >> x;
		cout << (isprime(x) ? "YES" : "NO") << endl;
	}
	return 0;
}
