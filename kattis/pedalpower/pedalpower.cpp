
#include <iostream>
#include <climits>
#include <unordered_map>
using namespace std;

int g[301][301][2];

int main(){
	int n;
	cin >> n;

	int x;
	cin >> x;	// number of bike paths

	for (int i = 0; i < n; ++i){
		for (int j = 0; j < n; ++j){
			g[i][j][0] = INT_MAX;
			g[i][j][1] = INT_MAX;
		}
	}

	while (x--){
		int u, v, t;
		cin >> u >> v >> t;
		g[u][v][1] = t;
		g[v][u][1] = t;
	}

	int y;
	cin >> y;	// number of non-bike paths
	while (y--){
		int u, v, t;
		cin >> u >> v >> t;
		g[u][v][0] = t;
		g[v][u][0] = t;
	}

	int z;
	cin >> z;

	unordered_map<int,bool> a;
	while (z--){
		int u;
		cin >> u;
		a.insert({u, false});
	}

	return 0;
}
