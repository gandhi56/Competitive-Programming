#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int maxn = 20001;
int n;
vector<int> adj[maxn*2];
vector<int> adjrev[maxn*2];
int val[maxn];
int marker, dfst, dfstime[maxn*2], dfsorder[maxn*2];
int group[maxn*2];

void dfs(int v){
	if (dfstime[v] != -1)	return;
	dfstime[v] = -2;
	int deg = adjrev[v].size();
	for (int i = 0; i < deg; ++i)	dfs(adjrev[v][i]);
	dfstime[v] = dfst++;
}

void dfsn(int v){
	if (group[v] != -1)	return;
	group[v] = marker;
	int deg = adj[v].size();
	for (int i = 0; i < deg; ++i)	dfsn(adj[v][i]);
}

bool solve(){
	dfst = 0;
	memset(dfstime, -1, sizeof(dfstime));
	for (int i = 0; i < n+n; ++i)	dfs(i);
	memset(val, -1, sizeof(val));
	for (int i = 0; i < n+n; ++i)	dfsorder[n+n-dfstime[i]-1] = i;
	memset(group, -1, sizeof(group));
	for (int i = 0; i < n+n; ++i){
		marker = i;
		dfsn(dfsorder[i]);
	}
	cout << marker << endl;
}

int main(){
	int t;
	cin>> t;
	while (t--){
		int m;
		cin >> n >> m;
		
		for (int i = 0; i < n; ++i){
			adj[i].clear(); adj[i].resize(n, 0);
			adjrev[i].clear(); adjrev[i].resize(n, 0);
		}

		while (m--){
			int u, v;
			cin >> u >> v;
			u--; v--;
			adj[u][v] = 1;
			adjrev[v][u] = 1;
		}

		solve();
	}
	return 0;
}
