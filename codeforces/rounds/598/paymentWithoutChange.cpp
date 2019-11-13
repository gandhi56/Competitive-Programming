#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	int q;
	cin >> q;
	while (q--){
		ll a, b, n, s;
		cin >> a >> b >> n >> s;
		if (s%n <= b and 1ll*a*n+b >= s){
			cout << "YES" << endl;
		}
		else{
			cout << "NO" << endl;
		}
	}
	return 0;
}
