#include <iostream>
#include <climits>
using namespace std;

const int inf = 999999;
int n, m, q;
int g[152][152];

void floydWarshall(){
	
	for (int i = 0; i < n; ++i)	g[i][i] = 0;
	
	for (int k = 0; k < n ;++k){
		for (int i = 0; i < n; ++i){
			for (int j = 0; j < n; ++j){

				if (g[i][k] >= inf or g[k][j] >= inf)	continue;

				g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
			}
		}
	}

	for (int k = 0; k < n; ++k){
		for (int i = 0; i < n; ++i){
			for (int j = 0; j < n; ++j){
				if (g[j][j] < 0 and g[k][j] < inf and g[j][i] < inf){
					g[k][i] = -inf;
				}
			}
		}
	}
}

int main(){

	while (cin >> n >> m >> q){

		if (n == 0 and m == 0 and q == 0)	break;

		for (int i = 0; i < 152; ++i){
			for (int j = 0; j < 152; ++j){
				g[i][j] = inf;
				if (i == j)	g[i][j] = 0;
			}
		}
		while (m--){
			int u, v, w;
			cin >> u >> v >> w;
			g[u][v] = min(w, g[u][v]);
		}

		floydWarshall();

		while (q--){
			int u, v;
			cin >> u >> v;
			if (g[u][v] >= inf){
				cout << "Impossible" << endl;
			}
			else if (g[u][v] <= -inf){
				cout << "-Infinity" << endl;
			}
			else{
				cout << g[u][v] << endl;
			}
		}
		cout << endl;
	}

	return 0;
}
