#include <bits/stdc++.h>
using namespace std;
int main(){
	int n, m;

	while (cin >> n >> m){
		if (n == 0 and m == 0)	break;
		unordered_set<long long> s;
		while (n--){
			long long x;
			cin >> x;
			s.insert(x);
		}

		long long cnt = 0;
		while (m--){
			long long x;
			cin >> x;
			if (s.find(x) != s.end())	++cnt;
		}

		cout << cnt << endl;
	}
	return 0;
}
