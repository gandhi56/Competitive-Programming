/*

	- construct a condensation graph
	- count the indeg of each scc
	- return max(#sccs with indeg = 0, #sccs with outdeg = 0)
	- if only one scc, output 0

*/


#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

typedef vector< vector<int> > graph;

int n, m;
bool used[20001];
int comp[20001];

void dfs1(graph& g, int u, vector<int>& order){
	used[u] = true;
	for (auto v : g[u]){
		if (!used[v])	dfs1(g, v, order);
	}
	order.push_back(u);
}

void dfs2(graph& gr, int u, int C){
	used[u] = true;
	comp[u] = C;
	cout << u << " ";
	for (auto v : gr[u]){
		if (!used[v])
			dfs2(gr, v, C);
	}
}

int main(){
	int t;
	cin >> t;

	while (t--){
		cin >> n >> m;
		graph g(n+1);
		graph gr(n+1);
		for (int i = 0; i < m; ++i){
			int u, v;
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}

		vector<int> order;
		memset(used, false, sizeof(used));
		for (int u = 1; u <= n; ++u){
			if (!used[u])	dfs1(g, u, order);
		}

		int count = 0;
		memset(used, false, sizeof(used));
		memset(comp, 0, sizeof(comp));
		int C = 1;
		for (int i = order.size()-1; i >= 0; --i){
			if (!used[order[i]]){
				dfs2(gr, order[i], C);
				count++;
				C++;
				cout << endl;
			}
		}

		int indeg[C+1];
		int outdeg[C+1];
		memset(indeg, 0, sizeof(indeg));
		memset(outdeg, 0, sizeof(outdeg));
		for (int u = 1; u <= n; ++u){
			for (auto v : g[u]){
				indeg[comp[v]]++;
				outdeg[comp[u]]++;
			}
		}
		
		for (int u = 1; u < C; ++u){
			cout << u << " : " << indeg[u] << " " << outdeg[u] << endl;
		}
		cout << endl;

	}

	return 0;
}
