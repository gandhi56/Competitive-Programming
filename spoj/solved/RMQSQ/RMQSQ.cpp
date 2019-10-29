#define MAXN 100001
#define K 25
#include <iostream>
using namespace std;

typedef long long ll;

int main(){
	int n;
	cin >> n;
	int a[n];
	for (int i = 0;i < n; ++i)
		cin >> a[i];

	// sparse table implementation
	int log[n+1];
	log[1] = 0;
	for (int i = 2; i <= n; ++i)
		log[i] = log[i/2] + 1;

	int st[n][K];
	for (int i = 0; i < n; ++i)
		st[i][0] = a[i];

	for (int j = 1; j <= K; ++j){
		for (int i = 0; i + (1<<j) <= n; ++i){
			st[i][j] = min(st[i][j-1], st[i + (1 << (j-1))][j-1]);
		}
	}

	int q;
	cin >> q;
	while (q--){
		int L, R;
		cin >> L >> R;
		int j = log[R - L + 1];
		int minval = min(st[L][j], st[R - (1 << j) + 1][j]);
		cout << minval << endl;
	}
	
	return 0;
}
