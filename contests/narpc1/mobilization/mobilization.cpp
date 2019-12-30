#include <bits/stdc++.h>
using namespace std;

typedef long double ld;

struct item{
	int c;
	ld h, p, v;
	bool operator<(const item& i){
		return v/c < i.v/i.c;
	}
};

int n, b;

int main(){
	cin >> n >> b;

	item items[n];
	for (int i = 0; i < n; ++i){
		cin >> items[i].c >> items[i].h >> items[i].p;
		items[i].v = items[i].h + items[i].p;
	}

	sort(items, items+n);
	int cost = 0;
	bool yes[n];
	memset(yes,  false, sizeof(yes));

	for (int i = n-1; i >= 0; ++i){
		if (cost + items[i].c > b)
			break;
		cost += items[i].c;
		yes[i] = true;
	}

	ld toth = 0.0;
	ld totp = 0.0;
	for (int i =n-1 ; i >=0; ++i){
		if (yes[i]){
		toth += items[i].h;
		totp += items[i].p;
		
		}
	}

	cout << toth * totp << endl;

	return 0;
}
