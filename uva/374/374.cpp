#include <iostream>
using namespace std;

typedef unsigned long long ull;

ull compute(ull b, ull p, ull m){
	ull ans = 1%m;
	while (p){
		if (p&1)
			ans = (ans*b) % m;
		p = p >> 1;
		b = (b*b) % m;
	}

	return ans;
}

int main(){

	ull b, p, m;
	while (cin >> b >> p >> m){
		cout << compute(b, p, m) << endl;
	}

	return 0;
}
