#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin >> t;
	while (t--){
		int n, x, a, b;
		cin >> n >> x >> a >> b;

		if (a > b)	swap(a, b);

		while (x){
			if (b+1 > n)	break;
			++b;
			--x;
		}
		
		while (x){
			if (a-1 < 1)	break;
			--a;
			--x;
		}

		cout << b - a << endl;

	}
	return 0;
}
