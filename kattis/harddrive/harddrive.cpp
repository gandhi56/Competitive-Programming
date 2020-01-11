#include <bits/stdc++.h>
using namespace std;
int main(){
	int n, c, b;
	cin >> n >> c >> b;

	vector<bool> hd(n, false);
	vector<bool> broken(n, false);
	while (b--){
		int x;
		cin >> x;
		broken[--x] = true;
	}

	if (c&1){
		hd[0] = true;
		c--;
	}
	
	int cnt = 0;
	for (int i = 2; i < n and c > 1; ++i){
		if (broken[i])	continue;
		if (!hd[i-1] and !hd[i+1]){
			hd[i] = true;
			cnt++;
			c -= 2;
			if (c == 0)	break;
		}
	}

	for (auto x : hd)	cout << (x?1:0);
	cout << endl;

	return 0;
}
