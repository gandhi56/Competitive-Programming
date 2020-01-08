#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000000

typedef vector< vector<int> > graph;

int indeg[MAXN];
int outdeg[MAXN];

int main(){
	int n;
	cin >> n;

	memset(indeg, 0, sizeof(indeg));
	memset(outdeg, 0, sizeof(outdeg));

	graph g(n);
	for (int i = 0; i < n; ++i){
		int u;
		cin >> u;
		--u;
		if (u >= 0){
			g[i].push_back(u);
			outdeg[i]++;
			indeg[u]++;
		}
	}	

	// find a vertex with indeg 1 and outdeg 0
	int s = 0;
	for (; s < n; ++s){
		if (indeg[s] == 1 and outdeg[s] == 0)	break;
	}

	// if no such s exists, pick s with lowest val
	s = 0;
	while (indeg[s] == 1 and outdeg[s] == 1)	s++;

	cout << s << endl;

	return 0;
}
