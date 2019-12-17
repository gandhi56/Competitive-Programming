#include <iostream>
using namespace std;

#define MAXN 26

bool a[MAXN][MAXN];
bool b[MAXN][MAXN];

void floydWarshall(){
	for (int k = 0; k < MAXN; ++k){
		for (int i = 0; i < MAXN; ++i){
			for (int j = 0; j < MAXN; ++j){
				a[i][j] |= (a[i][k] and a[k][j]);
				b[i][j] |= (b[i][k] and b[k][j]);
			}
		}
	}
}

int main(){
	int t;
	cin >> t;

	while (t--){

		for (int i =0  ;i < MAXN; ++i){
			for (int j =0 ; j < MAXN; ++j){
				a[i][j] = false;
				b[i][j] = false;
			}
		}

		int n;
		cin >> n;

		for (int i = 0; i < n; ++i){
			char from, to;
			cin >> from >> to;
			a[from-'A'][to-'A'] = true;
		}

		int m;
		cin >> m;

		for (int i =0 ; i < m; ++i){
			char from, to;
			cin >> from >> to;
			b[from-'A'][to-'A'] = true;
		}

		floydWarshall();

		bool eq = true;
		for (int i =0 ; i < MAXN; ++i){
			for (int j =0 ; j < MAXN; ++j){
				eq &= (a[i][j] == b[i][j]);
			}
		}
		cout << (eq ? "YES" : "NO") << endl;
		if (t)	cout << endl;
	}

	return 0;
}
