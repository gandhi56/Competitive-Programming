#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	int n;
	cin>> n;
	ll a[n];
	ll sum = 0;
	ll m = 0;
	for (int i = 0; i < n; ++i){
		cin >> a[i];
		m = max(m, a[i]);
		sum += a[i];
	}
	if (!(sum&1) and m <= sum-m){
		cout << "YES" << endl;
	}
	else{
		cout << "NO" << endl;
	}

	return 0;
}
