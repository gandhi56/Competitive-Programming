#include <iostream>
#include <vector>
#include <stack>
using namespace std;

typedef vector< vector<int> > graph;

int index[20005];
int low[20005];
int currIndex;

void scc(graph& g, int u, stack<int>& s){
	index[u] = currIndex;
	low[u] = currIndex;
	currIndex++;
	s.push(u);

	for (auto v : g[u]){
		if (index[v] == -1){
			scc(g, v, s);
		}
		low[u] = min(low[u], low[v]);
	}
}

void tarjan(graph g){
	stack<int> s;
	int count = 0;
	for (int u = 0; u < g.size(); ++u)	index[u] = -1;

	for (int u =0 ; u < g.size(); ++u){
		if (index[u] == -1){
			scc(g, u, s);
			count++;
		}
	}
	cout << count << endl;
}

int main(){
	int t;
	cin >> t;

	while (t--){
		int n, m;
		cin >> n >> m;

		currIndex = 0;

		graph g(n);
		while (m--){
			int u, v;
			cin >> u >> v;
			g[u-1].push_back(v-1);
		}

		tarjan(g);

	}

	return 0;
}
