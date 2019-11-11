#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;

	set<int> s;
	int a[n];
	for (int i = 0; i < n; ++i){
		cin >> a[i];
		s.insert(a[i]);
	}

	int ans = 0;
	for (int i = 0; i < n; ++i){
		if (s.find(a[i]) == s.end())	continue;
		int cnt = 1;
		int k = i;
		while (s.find(++k) != s.end())	++cnt;
		k = i;
		while (s.find(--k) != s.end())	++cnt;
		ans = max(ans, cnt);
	}
	cout << ans << endl;

	return 0;
}
