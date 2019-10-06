#include <iostream>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;

ull foo(ull m, ull n){
	ull g = __gcd(m, n);
	if (g == 1){
		return (m&1 and n&1 ? 1 : 0);
	}
	else{
		ull a = m / g;
		ull b = n / g;
		return foo(a, b) * g;
	}
}

int main(){
	ull m, n;
	cin >> m >> n;

	cout << foo(m, n) << endl;

	return 0;
}
