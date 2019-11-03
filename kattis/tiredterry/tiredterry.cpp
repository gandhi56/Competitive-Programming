#include <bits/stdc++.h>
using namespace std;
int main(){
	int n, p, d;
	cin >> n >> p >> d;

	string s;
	cin >> s;

	s = s+s;

	int cnt[2*n];	// cnt[i] = number of Zs in s[i..i+p-1]
	memset(cnt, 0, sizeof(cnt));

	// count how many seconds Terry was asleep for
	for (int i = 0; i < p; ++i){
		if (s[i] == 'Z')
			cnt[0]++;
	}

	for (int i = 1; i < n; ++i){
		cnt[i] = cnt[i-1];
		if (s[i-1] == 'Z')		cnt[i]--;
		if (s[i+p-1] == 'Z')	cnt[i]++;
	}

	#ifdef debug
	for (int i = 0; i <= n; ++i)
		cout << cnt[i] << endl;
	cout << endl;
	#endif

	int ans = 0;
	for (int i = 0; i < n; ++i){
		if (cnt[i] < d)
			ans++;
	}
	cout << ans << endl;
	return 0;
}
