#include <iostream>
#include <vector>
using namespace std;

typedef vector< vector<int> > graph;

bitset<100> colored;

int maxIndSet(graph& g, int u, int dp[]){
	if (dp[u] != 0)	return dp[u];
	
}

void color(graph& g){
	
}

int main(){

	int m;
	cin >> m;

	while (m--){
		colored.reset();
		int n, k;
		cin >> n >> k;
		graph g(n+1);
		for (int i =0 ; i < k; ++i){
			int u, v;
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		color(g);
	}

	return 0;
}
