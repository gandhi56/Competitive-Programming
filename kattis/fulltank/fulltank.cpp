#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

typedef pair<int,int> pii;
typedef vector< vector< pii> > > graph;

int dist[1002];

void dijkstra(graph& g, int s){

	for (int i =0 ; i < g.size(); ++i){
		dist[i] = INT_MAX;
	}

	priority_queue< pii, vector< pii >, greater<pii> > pq;
	pq.push({0,s});
	dist[s] = 0;

	while (!pq.empty()){
		
	}
}

int main(){
	int n, m;
	cin >> n >> m;

	graph g(n);
	for (int i = 0; i < m; ++i){
		int u, v, d;
		cin >> u >> v >> d;
		g[u].push_back({d, v});
		g[v].push_back({d, u});
	}

	int q;
	cin >> q;

	return 0;
}
