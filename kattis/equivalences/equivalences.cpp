#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

typedef unsigned long long ll;
typedef vector< vector<ll> > graph;

void dfs1(graph& g, ll u, bool* visited, vector<ll>& order){
	visited[u] = true;
	for (auto v : g[u]){
		if (!visited[v]){
			dfs1(g, v, visited, order);
		}
	}
	order.push_back(u);
}

void dfs2(graph& g, ll u, bool* visited){
	visited[u] = true;
	for (auto v : g[u]){
		if (!visited[v])
			dfs2(g, v, visited);
	}
}

int main(){
	int t;
	cin >> t;

	while (t--){
		ll n, m;
		cin >> n >> m;

		graph g(n);
		graph gr(n);
		while (m--){
			ll u, v;
			cin >> u >> v;
			g[u-1].push_back(v-1);
			gr[v-1].push_back(u-1);
		}

		vector<ll> order, scc;
		bool visited[n];
		memset(visited, false, sizeof(visited));
		for (ll u = 0; u < n; ++u){
			if (!visited[u]){
				dfs1(g, u, visited, order);
			}
		}

		vector< vector<int> > sccs, scc_graph;
		vector<int> scc_id(n, -1);
		memset(visited, false, sizeof(visited));
		while (!order.empty()){
			int u = order.back();
			order.pop_back();
			if (visited[u])	continue;
			dfs1(gr, u, visited, scc);
			sccs.emplace_back();
			while (!scc.empty()){
				sccs.back().push_back(scc.back());
				scc_id[scc.back()] = sccs.size() -1;
				scc.pop_back();
			}
		}

		scc_graph.resize(sccs.size());

		for (int i =0 ; i < sccs.size(); ++i){
			for (auto const& u : sccs[i]){
				for (auto const& v : g[u]){
					if (i != scc_id[v]){
						scc_graph[i].push_back(scc_id[v]);
					}
				}
			}
		}

		if (scc_graph.size() == 1){
			cout << 0 << endl;
			continue;
		}

		int nooutedges = 0;
		int noinedges = 0;
		vector<bool> in_edges(scc_graph.size(), false);
		for (int u = 0; u < scc_graph.size(); ++u){
			if (g[u].empty())	++nooutedges;
			for (auto const& v : g[u]){
				in_edges[v] = true;
			}
		}

		for (int i = 0; i < scc_graph.size(); ++i){
			if (!in_edges[i])	++noinedges;
		}

		if (noinedges > nooutedges){
			cout << noinedges << endl;
		}
		else{
			cout << nooutedges << endl;
		}


	}


	return 0;
}
