#include <iostream>
#include <vector>
using namespace std;

typedef vector< vector<int> > graph;

int e;
int r[100010];
int t[100010];

int dfs(graph g, int u, int rank){
	int total = 0;
	for (auto v : g[u]){
		if (r[v] < rank){
			total += t[v];
		}
		total += dfs(g, v, rank);
	}
	return total;
}

void solve(graph g){
	for (int i = 1; i <= e; ++i){
		cout << dfs(g, i, r[i]) << endl;
	}
}

int main(){
	cin >> e;
	graph g(e+1);
	for (int i = 1; i <= e; ++i){
		int m;
		cin >> m >> r[i] >> t[i];
		if (m != -1)	g[m].push_back(i);
	}

	solve(g);

	return 0;
}
