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

	int t;
	cin >> t;

	while (t--){

		int m, c;
		cin >> m >> c;
		
		int numEdges = c*(c-1)/2;
		int nodes[c];
		initSet(nodes, c);

		vector< pair<int,ii> > edges;
		for (int i = 0; i < numEdges; ++i){
			int u, v;
			int w;
			cin >> u >> v >> w;	
			edges.push_back({w, {u, v}});
		}

		sort(edges.begin(), edges.end());
		vector<ii> tree;
		int i = 0;
		int mst = 0;
		while (i < edges.size() and tree.size() < c - 1){
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

		if (m - mst >= c){
			cout << "yes" << endl;
		}
		else{
			cout << "no" << endl;
		}
	}
	return 0;
}
