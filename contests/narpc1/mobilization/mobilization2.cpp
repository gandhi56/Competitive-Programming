#include <bits/stdc++.h>
using namespace std;

#define MAXN 30001

typedef long double ld;

int n, m;
ld t[MAXN][3];

ld E(ld x, int i, int j){
	ld a = m / t[j][0];
	ld b = -t[i][0] / t[j][0];
	ld h1 = t[i][1];
	ld h2 = t[j][1];
	ld p1 = t[i][2];
	ld p2 = t[j][2];
	ld left = x * h1 + (a + b * x) * h2;
	ld right = x * p1 + (a + b * x) * p2;
	return left * right;
}

ld X(int i, int j){
	ld a = m / t[j][0];
	ld b = -t[i][0] / t[j][0];
	ld h1 = t[i][1];
	ld h2 = t[j][1];
	ld p1 = t[i][2];
	ld p2 = t[j][2];

	ld top = -1.0 * (a * h2 * p1 + a * p2 * h1 + 2.0 * p2 * h2 * a * b);
	ld bot = 2.0 * h1 * p1 + 2.0 * b * h2 * p1 + 2.0 * b * p2 * h1 + 2.0 * p2 * h2 * b * b;
	return top / bot;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; ++i){
		cin >> t[i][0] >> t[i][1] >> t[i][2];
	}

	ld ans = 0.0;
	for (int i =0 ; i < n-1; ++i){
		for (int j =i+1 ; j <n; ++j){
			ld a = m / t[j][0];
			ld b = -t[i][0] / t[j][0];
			ld h1 = t[i][1];
			ld h2 = t[j][1];
			ld p1 = t[i][2];
			ld p2 = t[j][2];
			
			ld ox = X(i, j);
			
			if (ox * t[i][0] > m){
				ans = max(ans, E(m / t[i][0], i, j));
			}
			else if (ox * t[i][0] < 0.0){
				ans = max(ans, E(m / t[j][0], i, j));
			}
			else{
				ans = max(ans, E(ox, i, j));
			}
		}
	}

	cout << fixed << setprecision(5);
	cout << ans << endl;

	return 0;
}













