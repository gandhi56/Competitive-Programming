#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

#define inf 0x3f3f3f3f

int n, m;

typedef pair<int,int> ii;
typedef unordered_map< int, vector< ii > > graph;

void dijkstra(graph& g, int s, int t){
	unordered_map<int,ii> dist;
	for (auto it : g){
		dist.insert({it.first, {inf, -1}});
	}
	
	dist[s] = 0;
	priority_queue<ii> pq;
	pq.push({0, s});
	while (!pq.empty()){
		ii curr = pq.top();
		pq.pop();
		if (curr.second == t)
			break;

		for (auto& it : g[curr.second]){
			if ()
			dist[it.second].first = min(dist[it.second], dist[it.first] + it.first);
		}
	}
}

int main(){

	while (1){
		cin >> n;
		if (n == 0)
			break;

		cin >> m;

		graph g;
		for (int i = 1; i <= n; ++i){
			g.insert({i, vector<ii>()});
		}
		for (int i = 0;i < m; ++i){
			int u, v, w;
			cin >> u >> v >> w;
			g[u].push_back({w, v});
			g[v].push_back({w, u});
		}

		// find vertices of odd degree, 
		// 	add an edge of min weight to that vertex
		vector<int> oddVertices;
		for (auto it : g){
			if (it.second.size()&1){
				oddVertices.push_back(it.first);
			}
		}

		for (int i =0; i < oddVertices.size(); ++i){
			for (int j = i+1; j < oddVertices.size(); ++j){
				// find the shortestpath

			}
		}
		

	}

	return 0;
}
