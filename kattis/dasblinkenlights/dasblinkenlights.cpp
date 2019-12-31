#include <bits/stdc++.h>
using namespace std;
int main(){
	int p, q, s;
	cin >> p >> q >> s;
	int lcm = p*q/__gcd(p, q);
	cout << (lcm<=s?"yes":"no") << endl;
	return 0;
}
