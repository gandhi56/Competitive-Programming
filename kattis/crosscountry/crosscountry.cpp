#include <bits/stdc++.h>
using namespace std;
int main(){
	int n, s, t;
	cin >> n >> s >> t;
	int d[n][n];
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < n; ++j){
			cin >> d[i][j];
		}
	}

	for (int k = 0; k < n; ++k){
		for (int i = 0; i < n; ++i){
			for (int j= 0; j < n; ++j){
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
	cout << d[s][t] << endl;

	return 0;
}
