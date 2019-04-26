#include <iostream>
#include <vector>
using namespace std;

struct edge{
	int u, v, c, f;
};

typedef vector< vector<edge> > graph;

int n, m, s, t;

int main(){
	cin >> n >> m >> s >> t;

	graph g(n);
	while (m--){
		edge e;
		cin >> e.u >> e.v >> e.c;
		g[u].push_back(e);
	}

	return 0;
}
