#include <iostream>
#include <vector>
#include <cstring>
#include <set>
using namespace std;

typedef vector< vector<int> > graph;

int n, m;
int timer;
vector<bool> visited;
vector<int> tin, low;
set<int> ap;

void dfs(graph& g, int v, int p = -1){
	visited[v] = true;
	tin[v] = low[v] = timer++;
	int children = 0;
	for (int to : g[v]){
		if (to == p)	continue;
		if (visited[to]){
			low[v] = min(low[v], tin[to]);
		}
		else{
			dfs(g, to, v);
			low[v] = min(low[v], low[to]);
			if (low[to] >= tin[v] and p != -1){
				ap.insert(v);
			}
			++children;
		}
	}

	if (p == -1 and children > 1){
		ap.insert(v);
	}
}

int main(){
	while (cin >> n >> m and n and m){
		graph g(n);
		for (int i =0 ; i < m; ++i){
			int u, v;
			cin >> u >> v;
			u--;
			v--;
			g[u].push_back(v);
		}

		timer = 0;
		visited.resize(n);	visited.assign(n, false);
		tin.resize(n);		tin.assign(n, -1);
		low.resize(n);		low.assign(n, -1);
		ap.clear();

		for (int u = 0; u < n; ++u){
			if (!visited[u])	dfs(g, u);
		}
	
		for (auto it = ap.begin(); it != ap.end(); ++it){
			cout << *it << endl;
		}

		cout << endl;
	
	}
	return 0;
}
