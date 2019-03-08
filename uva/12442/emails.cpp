#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

typedef vector< vector<int> > graph;

int dfs(graph& g, int u, bool* visited){
	int count = 1;
	visited[u] = true;
	for (auto& v : g[u]){
		if (!visited[v]){
			count += dfs(g, v, visited);
		}
	}

	return count;
}

int dfsMain(graph& g){
	bool visited[g.size()];

	int maxNodes = 0;
	int bestSource = 0;
	for (int s = 1; s <g.size(); ++s){
		memset(visited, false, sizeof(visited));
		int count = dfs(g, s, visited);
		if (maxNodes < count){
			maxNodes = count;
			bestSource = s;
		}
	}
	return bestSource;
}

int main(){
	int t;
	cin >> t;

	for (int T = 1; T <= t; ++T){
		int n;
		cin >> n;

		graph g(n+1);
		for (int i =0 ; i < n; ++i){
			int u, v;
			cin >> u >> v;
			g[u].push_back(v);
		}

		cout << "Case " << T << ": " << dfsMain(g) << endl;
	}

	return 0;
}
