#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

string s;

int main(){
	cin >> s;

	const int p = 31;
	const int m = 1e9 + 9;
	int n = s.length();
	vector<ll> p_pow(n);
	p_pow[0] = 1;
	for (int i=0; i < n; ++i)
		p_pow[i] = (p_pow[i-1] * p) % m;

	vector<ll> h(n+1, 0);
	for (int i = 0; i < n; ++i){
		h[i+1] = (h[i] + (s[i] - 'a' + 1) * p_pow[i]) % m;
	}

	for (int l = n-1; l >= 0; ++l){
		set<ll> hs;
		set<string> ans;
		for (int i = 0; i <= n - l; ++i){
			ll cur_h = (h[i+l] + m - h[i]) % m;
			cur_h = (cur_h * p_pow[n-i-1]);
			if (hs.find(cur_h) != hs.end()){
				// if substring already seen
				// print the subtring
				cout << s.substr(i, l) << endl;
				goto done;
			}
			hs.insert(cur_h);
		}

	}

	done:

	return 0;
}
