#include <iostream>
#include <vector>
using namespace std;

typedef vector< vector<string> > vis;

void solve(vis& g, vector<string>& items){
	for (int i =0 ; i < g.size(); ++i){
		
	}
}

int main(){
	int n, k;
	cin >> n >> k;

	vis g(n);
	for (int i =0; i < k; ++i){
		int u;
		string item;
		cin >> u >> item;
		g[u].push_back(item);
	}

	int q;
	cin >> q;

	vector<string> items;
	while (q--){
		string item;
		cin >> item;
		items.push_back(item);
	}

	solve(g, items);

	return 0;
}
