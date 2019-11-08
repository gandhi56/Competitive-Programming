#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
 
typedef unsigned long long ll;
 
ll m[1001][1001];
 
int main(){
	int n;
	cin >> n;
 
	for (int i =0 ; i < n; ++i){
		for (int j= 0; j < n; ++j){
			cin >> m[i][j];
		}
	}
 
	ll a[n];
	for (int i = 0; i < n; ++i){
		if (i == n-1){
			a[n-1] = m[0][n-1]/a[0];
		}
		else{
			a[i] = m[i][i+1];
			for (int j = i+3; j < n; ++j){
				a[i] = __gcd(a[i], m[i][j]);
			}

		}
		cout << a[i] << ' ';
	}
	return 0;
}
