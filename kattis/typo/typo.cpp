
#define MAXN 1000000
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int p = 31;
const int m = 1e9 + 9;
ll ppow[MAXN];

ll getHash(string& s, int i, int j){
	ll value = 0;
	ll ppow = 1;
	for (int k = i; k <= j; ++k){
		value = (value + (s[k] - 'a' + 1) * ppow) % m;
		ppow = (ppow * p) % m;
	}
	return value % m;
}

string getNewWord(string s, int i){
	if (i == 0)
		return s.substr(1, s.length() - 1);
	return s.substr(0, i) + s.substr(i+1, s.length()-i-1);
}

void fast(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
}

int main(){

	// precompute powers of p
	ll pp = 1 % m;
	for (int i = 0; i < MAXN; ++i){
		ppow[i] = pp;
		pp = (pp * p) % m;
	}

	int n;
	cin >> n;

	set<ll> _words;
	string words[n];
	vector<string> ans;
	for (int i = 0;  i < n; ++i){
		cin >> words[i];
		//cout << words[i] << " " << getHash(words[i], 0, words[i].length() - 1) << endl;
		_words.insert(getHash(words[i], 0, words[i].length()-1));
	}
	

	for (int i = 0; i < n; ++i){
		ll whash = getHash(words[i], 0, words[i].length() - 1);
		for (int j = 0; j < words[i].length(); ++j){

			// get hash for s[]
			ll del = ((words[i][j] - 'a' + 1) * ppow[j]) % m;
            ll aa = 0;

			if (_words.find(whash % m) != _words.end()){
				ans.push_back(words[i]);
				break;
			}
		}
	}

	for (auto& ss : ans)
		cout << ss << endl;

	if (ans.size() == 0)
		cout << "NO TYPOS" << endl;

	return 0;
}
