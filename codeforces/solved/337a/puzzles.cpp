
#define INF 0x3f3f3f3f
#include <bits/stdc++.h>
using namespace std;
int main(){
	int n, m;
	cin >> n >> m;

	int f[m];
	for (int i= 0; i < m; ++i)	cin >> f[i];

	sort(f, f+m);

	int ans = INF;
	for (int i =0; i+n-1 < m; ++i){
		for (int j = i+n-1; j < m; ++j){
			ans = min(ans, f[j] - f[i]);
		}
	}

	cout << ans << endl;

	return 0;
}
