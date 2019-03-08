#include <iostream>
#include <cstring>
using namespace std;

typedef long long int ll;

void solve(ll n, ll e){
	// find p and q st n = pq, use sieve

	bool isprime[n+1];
	memset(isprime, true, n+1);
	for (ll d = 2; d <= n; ++d){
		if (isprime[d]){
			for (ll i = 2; d*i <= n; ++i){
				isprime[d*i] = false;
			}
		}
	}

	ll p = 2, q;
	for (p = 2; p < n; ++p){
		if (isprime[p] and n%p == 0){
			q = n / p;
			if (isprime[q])	break;
		}
	}

	ll phi = (p - 1) * (q - 1);

	ll d;
	for (d = 2; d < phi; ++d){
		if (e * d % phi == 1){
			break;
		}
	}

	cout << d << endl;


}

int main(){
	int t;
	cin >> t;
	
	while (t--){
		ll n, e;
		cin >> n >> e;

		solve(n, e);

	}

	return 0;
}
