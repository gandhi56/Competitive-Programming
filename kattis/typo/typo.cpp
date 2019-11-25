#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD = 0x7fffffff;
const ll x = 123456;
const ll xinv = 1473977140;

vector<string> dict;
unordered_map<ll, vector<ll>> hashes;

ll gethash(string& s){
	ll h = 0;
	for (char c : s)	h = (h*x + c) % MOD;
	return h;
}

bool hit(ll h1, string& s, int i){
	// brute force
	if (hashes.find(h1) == hashes.end())	return false;
	for (int j : hashes[h1]){
		if (s.substr(0,i) + s.substr(i+1, s.length()) == dict[j])
			return true;
	}
	return false;
}

int main(){
	int n;
	cin >> n;

	dict.resize(n);
	for (int i = 0; i < n; ++i){
		cin >> dict[i];
		hashes[gethash(dict[i])].push_back(i);
	}

	bool typo = false;
	for (string& s : dict){
		ll h = gethash(s);
		ll partial = 0;
		ll xp = 1;

		for (int i = s.length()-1; i >= 0; --i){
			ll nextpartial = (partial + s[i]*xp) % MOD;
			ll h1 = (h - nextpartial + MOD) % MOD;
			h1 = (h1 * xinv + partial) % MOD;
			if (hit(h1, s, i)){
				cout << s << endl;
				typo = true;
				break;
			}

			partial = nextpartial;
			xp = (xp * x) % MOD;
		}
	}

	if (!typo)	cout << "NO TYPOS" << endl;

	return 0;
}
