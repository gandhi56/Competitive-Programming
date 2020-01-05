#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

int main(){
	ll n, d;
	cin >> n >> d;

	map<ll,ll> a;
	for (ll i = 0; i < n; ++i){
		ll x;
		cin >> x;
		if (a.find(x/d) == a.end()){
			a[x/d] = 0;
		}
		a[x/d]++;
	}

	ll cnt = 0;
	for (auto x : a){
		ll r = x.second;
		cnt += ((r) * (r-1)) / 2;
	}
	cout << cnt << endl;

	return 0;
}
