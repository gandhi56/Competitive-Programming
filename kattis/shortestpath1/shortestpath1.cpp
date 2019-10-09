#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <functional>
using namespace std;

typedef vector< vector< pair<int,int> > > graph;

void dijkstra(graph g, int s, int* dist){
	//int dist[g.size()];
	for (int i = 0; i < g.size(); ++i){
		dist[i] = (i == s? 0 : -1);
	}

	priority_queue< pair<int,int>, vector< pair<int,int> >, greater< pair<int,int> > > pq;
	pq.push( make_pair(0, s) );
	while (!pq.empty()){
		int u = pq.top().second;
		pq.pop();
		

		for (pair<int,int>  next : g[u]){
			int v = next.first;
			int weight = next.second;
			if (dist[v] == -1 || dist[u] + weight < dist[v]){
				dist[v] = dist[u] + weight;
				pq.push( make_pair(dist[v], v) );
			}
		}
	}

	/*
	for (int i = 1; i < g.size(); ++i){
		if (i != s){
			if (dist[i] == INT_MAX){
				cout << "-1 ";
			}
			else{
				cout << dist[i] << " ";
			}
		}
	}
	cout << endl;
	*/

}

int main(){
	while (true){
		int n, m, q, s;
		cin >> n >> m >> q >> s;

		if (n == 0)	break;
		graph g(n);
		while (m--){
			int u, v, w;
			cin >> u >> v >> w;

			g[u].push_back({v, w});
			g[v].push_back({u, w});
		}

		int dist[n];
		dijkstra(g, s, dist);

		while (q--){
			int u;
			cin >> u;
			if (dist[u] == -1){
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
