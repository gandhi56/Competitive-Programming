#include <iostream>
#include <cmath>
using namespace std;

typedef unsigned long long ull;

ull fastExp(ull b, ull p, ull m){
	ull ans = 1%m;
	while (p){
		if (p&1)
			ans = (ans*b) % m;
		p = p >> 1;
		b = (b*b) % m;
	}

	return ans % m;
}

bool is_carmichael(int n){
	// count the number of prime factors

	// check if n is composite
	for (ull d = 2; d*d <= n; ++d){
		if (n%d == 0){
			return true;
		}
	}
	return false;
}

int main(){
	int n;
	while (cin >> n){
		if (n ==0)	break;

		if (is_carmichael(n)){
			cout << "The number " << n << " is a Carmichael";
			cout << " number." << endl;
		}
		else{
			cout << n << " is normal." << endl;
		}

	}
	return 0;
}
