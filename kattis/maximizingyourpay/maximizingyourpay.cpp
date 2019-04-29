#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

#define MAXN 12

int n, m;
bool g[MAXN][MAXN];

void print(vector<int> v){
	for (auto x : v)	cout << x << " ";
	cout << endl;
}

void solve(){
	int best = 0;
	vector<int> v;
	for (int i = 0; i < n; ++i)	v.push_back(i);
	do{
		int N = n-1;
		while (!g[v[N]][v[0]] and N)	N--;

		// v[N] and v[0] are connected here
		bool ok = true;
		for (int i = 0; i < N-1 and ok; ++i){
			ok = g[v[i]][v[i+1]];
		}

		if (ok){
			cout << N+1 << " : ";
			print(v);
			best = max(best, N+1);
		}

	}while (next_permutation(v.begin()+1, v.end()));
	cout << best << endl;
}

int main(){
	while (cin >> n >> m){
		memset(g, false, sizeof(g));
		for (int i =0; i < m; ++i){
			int x, y;
			cin >> x >> y;
			g[x][y] = true;
			g[y][x] = true;
		}
		solve();
	}


	return 0;
}
