#include <iostream>
using namespace std;

const int inf = 999999;
int dist[1001];

struct edge{
	int u, v, w;
};

void bellmanFord(edge edges[], int m, int n, int s){
	for (int i = 0; i < n; ++i){
		dist[i] = inf;
		if (i == s)	dist[i] = 0;
	}

	for (int k = 0; k < n-1; ++k){
		for (int i =0 ; i < m; ++i){
			int u = edges[i].u;
			int v = edges[i].v;
			int w = edges[i].w;
			if (dist[u] == inf)	continue;
			dist[v] = min(dist[v], dist[u] + w);
		}
	}

	while (1){
		int nchanged = 0;
		for (int i = 0; i < m; ++i){
			if (dist[edges[i].v] == -inf){
				continue;
			}
			if (dist[edges[i].u] == inf){
				continue;
			}
			if (dist[edges[i].u] + edges[i].w < dist[edges[i].v]){
				dist[edges[i].v] = -inf;
				nchanged++;
			}
		}
		if (nchanged == 0)	break;
	}
}

int main(){
	int n, m, q, s;
	while (cin >> n >> m >> q >> s){
		if (n == 0 and m == 0 and q ==  0 and s == 0)	break;
		edge edges[m];
		for (int i =0 ; i < m; ++i){
			cin >> edges[i].u >> edges[i].v >> edges[i].w;
		}

		bellmanFord(edges, m, n, s);

		while (q--){
			int u;
			cin >> u;
			if (dist[u] <= -inf){
				cout << "-Infinity" << endl;
			}
			else if (dist[u] >= inf){
				cout << "Impossible" << endl;
			}
			else{
				cout << dist[u] << endl;
			}
		}
		cout << endl;
	}

	return 0;
}
