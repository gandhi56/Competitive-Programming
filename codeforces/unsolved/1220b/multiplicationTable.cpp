#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
int main(){
	int n;
	cin >> n;
	ull m[n][n];
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < n; ++j){
			cin >> m[i][j];
		}
	}

	ull a[n];
	int i, j, k;
	for (i = 0; i+2 < n; ++i){
		j = i+1;
		k = i+2;
		a[i] = sqrt( m[i][j]*m[i][k]/m[j][k] );
	}
	j = 0;
	k = 2;
	a[n-2] = sqrt( m[n-2][j]*m[n-2][k]/m[j][k] );
	k = 1;
	a[n-1] = sqrt( m[n-1][j]*m[n-1][k]/m[j][k] );

	for (int i =0; i < n; ++i)	cout << a[i] << ' ';

	return 0;
}
