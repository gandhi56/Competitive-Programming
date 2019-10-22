#include <iostream>
using namespace std;

typedef long long ll;

int main(){
	ll n, m, k;
	cin >> n >> m >> k;
	ll hi = n / k;	// each group has k gnomes
	ll lo = max(hi-m+1, 0LL);
	ll worstDamage = 0;

	for (ll u = lo; u <= hi; ++u){
		ll rem = n - k*u;	// u = number of groups of size k, rem = remaining gnomes
		ll v = rem / m;	// v groups of the remaining gnomes of size m
		ll q = rem % m;	// rest

		ll dmg = 0;
		dmg += (k * (u * (u + 1)) / 2 + u*rem) + (v*(m*(m+1)/2)) + (q*(q+1)/2);
		worstDamage = max(worstDamage, dmg);
	}
	cout << worstDamage << endl;

	return 0;
}
