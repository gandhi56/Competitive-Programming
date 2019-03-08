#include <iostream>
#include <bitset>
using namespace std;

typedef long long int ll;

bitset<100000001> comp;

int main(){
	ll n, q, count = 1;
	cin >> n >> q;

	comp[1] = 1;

	for (ll i = 3; i <= n; i += 2){
		if (!comp[i]){
			++count;
			for (ll j = i*3; j <= n; j += 2*i){
				comp[j] = 1;
			}
		}
	}

	cout << count << endl;

	while (q--){
		ll x;
		cin >> x;
		if (x%2)	cout << !comp[x] << endl;
		else if (x == 2)	cout << "1" << endl;
		else		cout << "0" << endl;
	}
	return 0;
}
