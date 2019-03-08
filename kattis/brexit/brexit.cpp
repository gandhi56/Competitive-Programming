#include <iostream>
#include <vector>
using namespace std;

typedef vector< vector<int> > graph;

int main(){
	int c, p, x, l;
	cin >> c >> p >> x >> l;

	graph g(c);
	for (int i =0 ; i < p; ++i){
		int u, v;
		cin >> u >> v;

		g[u].push_back(v);
		g[v].push_back(u);
	}

	return 0;
}
