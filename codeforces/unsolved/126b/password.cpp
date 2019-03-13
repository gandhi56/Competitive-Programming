#include <iostream>
#include <cstring>
using namespace std;

typedef long long ll;


ll h(string& s, int i, int j){
	const int p = 31;
	const int m = 1e9 + 9;
	ll h = 0;
	ll pow = 1;
	for (int k = i; k < j; ++k){
		h = (h + (s[k] - 'a' + 1) * pow) % m;
		pow = (pow * p) % m;
	}

	return h;
}

ll h(string s){
	return h(s, 0, s.size());
}

void solve(string& s){
	if (s.size() <= 2){
		cout << "Just a legend" << endl;
		return;
	}
	int len = 1;
	ll hashval;
	int p = -1;
	int q = -1;
	while (len <= s.size()-2){
		if (h(s, 0, len) == (hashval = h(s, s.size()-len, s.size()))){
			for (int k = 1; k+len <= s.size()-1; ++k){
				if (h(s, k, k+len) == hashval){
					p = k;
					q = k+len-1;
				}
			}
		}
		len++;
	}

	if (p == -1 and q == -1){
		cout << "Just a legend" << endl;
	}
	else{
		for (int i = p; i <= q; ++i){
			cout << s[i];
		}
		cout << endl;
	}

}

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	string s;
	cin >> s;

	solve(s);

	return 0;
}
