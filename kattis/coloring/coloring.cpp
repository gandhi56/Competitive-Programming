#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
using namespace std;

typedef vector< vector<int> > vvi;
int n;
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

	scanf("%d", &n);
	
	int delta = 0;
	vvi g(n);
	for (int i = 0; i < n; ++i){
		char c = ' ';
		int j;
		while (1){
			scanf("%d%c", &j, &c);
			g[i].push_back(j);
			if (c == '\n')	break;
		}

		delta = max(delta, (int)g[i].size());
	}

	for (int k = 1; k <= delta + 1; ++k){
		color[0] = 1;
		if (solve(g, k)){
			printf("%d\n", k);
			break;
		}
	}

	return 0;
}
