#include <bits/stdc++.h>
using namespace std;

int main(){
	long long x, y, n;
	char _;
	while (cin >> x >> _ >> n){
		long long cnt = 0;
		for (x = n+1; x <= 2*n; ++x){
			y = (x*n) / (x-n);
			if (n*(x+y) == x*y and x <= y){
				//cout << x << ' ' << y << endl;
				++cnt;
			}
		}
		cout << cnt << endl;
	}
	return 0;
}
