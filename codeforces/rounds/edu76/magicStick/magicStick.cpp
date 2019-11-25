#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main(){
	int t;
	cin >> t;
	while (t--){
		ll x, y;
		cin >> x >> y;

	/*
		queue<ll> q;
		q.push(x);
		set<ll> seen;
		seen.insert(x);
		while (!q.empty()){
			x = q.front(); q.pop();

			if (x == y){
				cout << "YES" << endl;
				break;
			}

			if (!(x&1)){
				if (3*x/2 <= 1000000000LL and seen.find(3*x/2) == seen.end()){
					q.push(3*x/2);
					seen.insert(3*x/2);
				}
			}
			if (x > 1){
				if (seen.find(x-1) == seen.end()){
					q.push(x-1);
					seen.insert(x-1);
				}
			}
		}

		if (seen.find(y) == seen.end()){
			cout << "NO" << endl;
		}
	*/

		if (x >= y){
			cout << "yes" << endl;
		}
		else{
			set<ll> seen;
			while (x < y){
				seen.insert(x);
				if (x&1){
					x = (3*(x-1))/2;
					if (seen.find(x) != seen.end()){
						break;
					}
				}
				else{
					x = (3*x)/2;
				}
			}
			if (x == y){
				cout << "yes" << endl;
			}
			else{
				cout << "no" << endl;
			}
		}


	}
	return 0;
}
