#include <iostream>
#include <tuple>
using namespace std;


long fastExp(long a, long b, long x){
	long ans = 1;
	while (b){
		if (b&1)	ans = (ans*a) % x;
		b >>= 1;
		a = (a*a) % x;
	}

	return ans % x;
}

tuple<long,long,long> gcd(long a, long b){
	if (a == 0)	return make_tuple(b, 0, 1);
	long d, x, y;
	tie(d, x, y) = gcd(b%a, a);
	return make_tuple(d, (y - (b/a) * x), x);
}

void solve(long a, long b, long x){
	if (b >= 0){
		cout << fastExp(a, b, x) << endl;
	}
	else{
		// compute the inverse of a
		// a*p + k*x = 1
		tuple<long,long,long> t = gcd(a, x);
		long inv = get<1>(t);
		long exp = fastExp(inv, -b, x);
		while (exp < 0)	exp += x;
		cout << exp << endl;
	}
}

int main(){
	int t;
	cin >> t;
	while (t--){
		long a, b, x;
		cin >> a >> b >> x;
		solve(a, b, x);
	}
	return 0;
}
