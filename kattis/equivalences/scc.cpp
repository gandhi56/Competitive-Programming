#include <iostream>
#include <vector>
using namespace std;

typedef vector< vector<int> > graph;

int id[20010];
int 

int main(){
	int t;
	cin >> t;

	while (t--){
		int n, m;
		cin >> n >> m;

		graph g(n+1);
		while (m--){
			int u, v;
			cin >> u >> v;
			g[u].push_back(v);
		}

	}
	return 0;
}
