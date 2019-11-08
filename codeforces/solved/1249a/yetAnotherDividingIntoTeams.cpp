#include <bits/stdc++.h>
using namespace std;
int main(){
	int q;
	cin >> q;
	while (q--){
		int n;
		cin >> n;

		int a[n];
		for (int i = 0; i < n; ++i)	cin >> a[i];
		sort(a, a+n);
		
		int team[n];
		memset(team, 0, sizeof(team));

		int ans = 0;
		for (int i = 0; i < n; ++i){
			for (int t = 1; t <= n; ++t){
				bool done = true;
				for (int j = i-1; j >= 0 and done; --j){
					if (abs(a[i] - a[j]) == 1 and team[j] == t)	done = false;
					if (abs(a[i] - a[j]) > 1)	break;
				}
				if (done){
					team[i] = t;
					ans = max(ans, t);
					break;
				}
			}
		}

		#ifdef debug
		for (int i = 0; i < n; ++i){
			cout << i << ' ' << a[i] << ' ' << team[i] << endl;
		}
		#endif

		cout << ans << endl;
	}


	return 0;
}
