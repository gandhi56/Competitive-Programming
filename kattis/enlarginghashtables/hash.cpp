#include <iostream>
using namespace std;

typedef unsigned long long ull;

bool isprime(ull n){
	for (ull d = 2; d*d <= n; ++d){
		if (n%d == 0)	return false;
	}
	return true;
}

int main(){
	ull n;
	while (1){
		cin >> n;

		if (n == 0)	break;

		for (ull p = 2*n+1;; ++p){
			if (isprime(p)){
				cout << p << " ";
				break;
			}
		}

		if (!isprime(n)){
			cout << "(" << n << " is not prime)";
		}
		cout << endl;
	}
	return 0;
}
