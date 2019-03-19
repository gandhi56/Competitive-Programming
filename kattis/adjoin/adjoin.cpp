#include <iostream>
#include <vector>
#include <queue>

#define INF 10000007

using namespace std;
typedef vector< vector<int> > graph;
int c, l;

void bfs(graph& g, int s, int* dist){
	for (int i = 0; i < g.size(); ++i){
		dist[i] = -1;
	}
	queue<int> q;
	q.push(s);
	dist[s] = 0;
	while (!q.empty()){
		int u = q.front();
		q.pop();
		for (auto& v : g[u]){
			if (dist[v] != -1)	continue;
			q.push(v);
			dist[v] = dist[u] + 1;
		}
	}
}

int main(){
	cin >> c >> l;

	graph g(c);

	for (int i =0 ; i < l; ++i){
		int u, v;
		cin >> u >> v;

		g[u].push_back(v);
		g[v].push_back(u);
	}

	// find the node with the largest diameter

	return 0;
}
