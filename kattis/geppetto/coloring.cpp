#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
using namespace std;

typedef vector< vector<int> > vvi;
int n, m;
int color[14];

int uncoloredNode(){
	for (int i = 0; i < n; ++i){
		if (color[i] == 0)	return i;
	}
	return -1;
}

bool colorable(vvi& g, int u, int col){
	for (auto& v : g[u]){
		if (color[v] == col)	return false;
	}
	return true;
}

bool solve(vvi& g, int k){
	int u = uncoloredNode();
	if (u == -1)	return true;
	for (int c = 1; c <= k; ++c){
		if (!colorable(g, u, c))	continue;
		color[u] = c;
		if (solve(g, k))	return true;
		color[u] = 0;
	}
	return false;
}

int main(){
	for (int i = 0 ;i < n; ++i){
		color[i] = 0;
	}

	scanf("%d %d", &n, &m);
	
	int delta = 0;
	vvi g(n+1);
	for (int i = 0; i < m; ++i){
		int u, v;
		scanf("%d%d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u)
	}

	for (int u = 1; u <= n; ++u)
		delta = max(delta, (int)g[u].size());
	
	for (int k = 1; k <= delta + 1; ++k){
		color[0] = 1;
		if (solve(g, k)){
			printf("%d\n", k);
			break;
		}
	}

	return 0;
}
