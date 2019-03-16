#include <iostream>
using namespace std;

#define maxn 200010

char word[maxn];
int p[maxn];

void solve(string s){
	int wordSize = s.size() * 2 + 1;
	int c = 0;
	int r = -1;

	for (int i = 0; i < wordSize; ++i){
		word[i*2+1] = s[i];
	}

	for (int i = 0; i < wordSize; ++i){
		int rad = 0;
		if (i < r){
			rad = min(p[2*c-i], r - i);
		}

		while (i+rad < wordSize and i - rad >= 0 and word[i-rad] == word[i+rad]){
			rad++;
		}

		--rad;
		p[i] = rad;

		if (i+rad > r){
			c = i;
			r = i + rad;
		}
	}
}


int main(){
	string s;
	while (cin >> s){
		solve(s);
	}

	return 0;
}
