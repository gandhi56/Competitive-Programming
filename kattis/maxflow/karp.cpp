#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <functional>
using namespace std;


typedef long long ll;

#define INF (1ll<<60)
struct edge{
	int v;
	ll cap;
	edge(int vv, ll c)	:
		v(vv), cap(c)	{}
};

typedef vector< vector< edge > > graph;

bool bfs(graph& g, int s, int t, int par[]){
	bool visited[g.size()];
	for (int i = 0; i < g.size(); ++i){
		visited[i] = false;
		par[i] = -1;
	}

	queue<int> q;
	q.push(s);
	visited[s] = true;
	while (!q.empty()){
		int u = q.front();
		q.pop();
		if (u == t)	return true;
		for (auto ed : g[u]){
			if (visited[ed.v] or ed.cap <= 0)	continue;
			visited[ed.v] = true;
			q.push(ed.v);
			par[ed.v] = u;
		}
	}
	return false;
}

int getIndex(graph& g, int u, int v){
	int k = 0;
	while (k < g[u].size()){
		if (g[u][k].v == v)	return k;
		k++;
	}
	return -1;
}

void edmondsKarp(graph& g, int s, int t){
	graph rg(g.size());
	
	// create residual graph
	for (int u = 0; u < g.size(); ++u){
		for (int i = 0; i < g[u].size(); ++i){
			rg[u].push_back(edge(g[u][i].v, g[u][i].cap));
		}
	}

	int par[g.size()];
	ll maxflow = 0;

	while (bfs(rg, s, t, par)){
		// find augmenting flow
		ll augflow = INF;
		for (int v = t; v != s; v = par[v]){
			int u = par[v];
			int k = getIndex(rg, u, v);
			if (k == -1)	continue;
			augflow = min(augflow, rg[u][k].cap);
		}

		// augment flow
		for (int v = t; v != s; v = par[v]){
			int u = par[v];
			int k = getIndex(rg, u, v);
			if (k == -1)	continue;
			rg[u][k].cap = rg[u][k].cap - augflow;
			k = getIndex(rg, v, u);
			if (k == -1)	continue;
			rg[v][k].cap = rg[v][k].cap + augflow;
		}
		maxflow += augflow;
	}
	cout << g.size() << " " << maxflow << " ";

	// count number of edges
	int count = 0;
	for (int u = 0; u < g.size(); ++u){
		for (int i = 0; i < g[u].size(); ++i){
			count += (g[u][i].cap - rg[u][i].cap > 0);
		}
	}
	cout << count << endl;
	for (int u = 0; u < g.size(); ++u){
		for (int i = 0; i < g[u].size(); ++i){
			if (g[u][i].cap - rg[u][i].cap > 0){
				cout << u << " " << g[u][i].v << " ";
				cout << g[u][i].cap - rg[u][i].cap << endl;
			}
		}
	}
}

int main(){
	int n, m, s, t;
	cin >> n >> m >> s >> t;

	graph g(n);
	while (m--){
		int u, v, c;
		cin >> u >> v >> c;
		g[u].push_back(edge(v, c));
	}

	edmondsKarp(g, s, t);

	return 0;
}
