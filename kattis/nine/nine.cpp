#include <iostream>
#include <cmath>
using namespace std;

typedef unsigned long long ll;

const ll p = 1e9+7;

ll f(ll x){
	if (x < 10)	return (ll)pow(9, x);
	ll tmp = f(x/2);
	if (x%2 == 0)	return (tmp*tmp) % p;
	return (9 * tmp * tmp) % p;
}

int main(){
	int t;
	cin >> t;

	while (t--){
		ll x;
		cin >> x;

		x %= p-1;

		ll count = (8 * f(x-1)) % p;
		cout << count << endl;
	}

	return 0;
}
