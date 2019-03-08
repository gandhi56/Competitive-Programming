#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int,int> ii;

void initSet(int par[], int size){
	for (int i = 0; i < size; ++i)
		par[i] = i;
}

int findSet(int par[], int i){
	return (par[i] == i)	?	i : (par[i] = findSet(par, par[i]));
}

void unionSet(int par[], int i, int j){
	par[findSet(par, i)] = findSet(par, j);
}

bool isSameSet(int par[], int i, int j){
	return findSet(par, i) == findSet(par, j);
}

int main(){
	int n, m;
	while (cin >> n >> m){

		if (n == 0 and m == 0)	break;

		int nodes[n];
		initSet(nodes, n);

		vector< pair<int,ii> > edges;
		for (int i = 0; i < m; ++i){
			int u, v;
			int w;
			cin >> u >> v >> w;	
			edges.push_back({w, {u, v}});
		}

		sort(edges.begin(), edges.end());
		vector<ii> tree;
		int i = 0;
		int mst = 0;
		while (i < edges.size() and tree.size() < n - 1){
			int u = edges[i].second.first;
			int v = edges[i].second.second;
			int w = edges[i].first;
			if (!isSameSet(nodes, u, v)){
				unionSet(nodes, u, v);
				mst += w;
				tree.push_back({min(u, v), max(u, v)});
			}
			i++;
		}

		if (tree.size() < n - 1){
			cout << "Impossible" << endl;
			continue;
		}

		cout << mst << endl;
		sort(tree.begin(), tree.end());
		for (auto e : tree){
			cout << e.first << " " << e.second << endl;
		}

	}

	return 0;
}
