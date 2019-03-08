#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

typedef vector< vector<int> > graph;

int main(){
	int p, t;
	cin >> p >> t;

	graph g(p+1);

	int i, j;
	while (cin >> i >> j){
		g[i].push_back(j);
	}

	set< vector<int> > G;
	for (i = 1; i <= p; ++i){
		sort(g[i].begin(), g[i].end());
		G.insert(g[i]);
	}

	cout << G.size() << endl;
	return 0;
}
