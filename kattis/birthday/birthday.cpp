#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

typedef pair<int,int> ii;
typedef vector< vector<int> > graph;

void dfs(graph g, int u, bool* visited, ii e){
	visited[u] = true;
	for (auto v : g[u]){
		if (u == e.first and v == e.second)	continue;
		if (v == e.first and u == e.second)	continue;
		if (!visited[v])
			dfs(g, v, visited, e);
	}
}

bool is_bridge(graph g, ii e){
	bool visited[g.size()];
	memset(visited, false, sizeof(visited));
	int count = 0;
	for (int u =0 ; u < g.size(); ++u){
		if (!visited[u]){
			dfs(g, u, visited, e);
			count++;
		}
	}
	return count > 1;
}

void solve(graph g){
	for (int u = 0; u < g.size(); ++u){
		for (auto v : g[u]){
			if (u < v and is_bridge(g, {u, v})){
				cout << "Yes" << endl;
				return;
			}
		}
	}
	cout << "No" << endl;
}

int main(){
	int p, c;

	while (cin >> p >> c){
		if (p == 0 and c == 0)	break;
		graph g(p);
		for (int i =0 ; i < c; ++i){
			int a, b;
			cin >> a >> b;
			g[a].push_back(b);
			g[b].push_back(a);
		}

		solve(g);

	}

	return 0;
}
