#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

ld N;

inline int cnt(ll x){
	return x*(x-1)/2;
}

double p(int m, int n){
	return N * (m + cnt(2*n));
}

int main(){
	ll m, n;
	cin >> m >> n;
 	
	int a = cnt(2*m+2*n);
	N = (long double)(1/a);

	double ans = 1.0 - p(m, n);
	int t = a-1;
	while (t--){
		ans *= (1 - p(m-2, n) - p(m-1, n-1) - p(m, n-2));
	}

	cout << fixed << setprecision(8);
	cout << ans << endl;

	return 0;
}
