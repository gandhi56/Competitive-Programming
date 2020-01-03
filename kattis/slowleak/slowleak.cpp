
//#define debug
#define inf 0xffffffff

#include <iostream>
#include <unordered_map>
#include <vector>
#include <cstring>
using namespace std;

typedef long long ll;

int n, m, t, d;

bool isterm(int x){
	return x ==1 or x == n;
}

int main(){
	cin >> n >> m >> t >> d;

	ll g[n+1][n+1];
	ll g2[n+1][n+1];

	for (int i = 0; i < n+1; ++i){
		for (int j = 0; j < n+1; ++j){
			g[i][j] = inf;
			g2[i][j] = inf;
		}
	}

	bool isrepair[n+1];
	memset(isrepair, false, sizeof(isrepair));
	while (t--){
		int x;
		cin >> x;
		isrepair[x] = true;
	}
	isrepair[1] = true;
	isrepair[n] = true;

	for (int i = 0; i < m; ++i){
		ll u, v, w;
		cin >> u >> v >> w;
		g[u][v] = w;
		g[v][u] = w;
	}
	// print graph
	#ifdef debug
	cout << "input" << endl;
	for (int i = 1; i <= n; ++i){
		for (int j = 1; j <= n; ++j){
			cout << g[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	#endif

	for (int k = 1; k <= n; ++k){
		for (int i = 1; i <= n; ++i){
			for (int j = 1; j <= n; ++j){
				if (g[i][k] == inf or g[k][j] == inf)
					continue;
				g[i][j]= min(g[i][j], g[i][k] + g[k][j]);
			}
		}
	}

	// print graph
	#ifdef debug
	cout << "fw1" << endl;
	for (int i = 1; i <= n; ++i){
		for (int j = 1; j <= n; ++j){
			cout << g[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	#endif

	// construct g2
	for (int i = 1; i <= n; ++i){
		for (int j = i+1; j <= n; ++j){
			if (isrepair[i] and isrepair[j] and g[i][j] <= d) {
				g2[i][j] = g2[j][i] = g[i][j];
			}
		}
	}

	// run floyd warshall on g2
	for (int k = 1; k <= n; ++k){
		for (int i = 1; i <= n; ++i){
			for (int j = 1; j <= n; ++j){
				if (g2[i][k] == inf or g2[k][j] == inf)
					continue;
				g2[i][j]= min(g2[i][j], g2[i][k] + g2[k][j]);
			}
		}
	}
	// print graph
	#ifdef debug
	for (int i = 1; i <= n; ++i){
		for (int j = 1; j <= n; ++j){
			cout << g2[i][j] << " ";
		}
		cout << endl;
	}
	#endif

	if (g2[1][n] == inf){
		cout << "stuck " << endl;
	}
	else{
		cout << g2[1][n] << endl;
	}

	return 0;
}
