
#define MAXN 100000
#define K	 25

#include <bits/stdc++.h>
using namespace std;

int a[MAXN];
int st[MAXN][K];

int f(int l, int r){
	int d = __gcd(a[l], a[l+1]);
	for (int i = l+2; i <= r; ++i){
		d = __gcd(d, a[i]);
	}
	return d;
}

void show_st(int n){
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < K; ++j){
			cout << st[i][j] << ' ';
		}
		cout << endl;
	}
}

int main(){


	int n;
	cin >> n;

	// input array
	for (int i = 0; i < n; ++i){
		cin >> a[i];
		st[i][0] = a[i];
	}

	// fill up sparse table
	for (int j = 1; j <= K; ++j){
		for (int i = 0; i + (1 << j) <= n; ++j){
			st[i][j] = f(st[i][j-1], st[i+(1<<(j-1))][j-1]);
		}
	}

	show_st(n);

	int q;

	cin >> q;

	while (q--){
		int x;
		cin >> x;

	}

	return 0;
}
