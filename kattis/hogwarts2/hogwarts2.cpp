#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef vector< vector<int> > graph;

int main(){
	int n;
	cin >> n;

	graph g, h;
	g.push_back({0,0,0,0});
	h.push_back({0,0,0,0});

	for (int i = 0; i < n; ++i){
		vector<int> adj(4);
		for (auto& x : adj)	cin >> x;
		g.push_back(adj);
	}
	for (int i = 0; i < n; ++i){
		vector<int> adj(4);
		for (auto& x : adj)	cin >> x;
		h.push_back(adj);
	}

	/*
	map<ii, vector<ii>> gh;
	for (int k = 0; k < 4; ++k){
		for (int i = 0; i <= n; ++i){
			for (int j = 0; j <= n; ++j){
				gh[{i,j}].push_back({g[i][k], h[j][k]});
			}
		}
	}
	*/

	map<ii, bool> visited;
	for (int i = 0; i <= n; ++i){
		for (int j =0 ; j <= n; ++j){
			visited[{i,j}] = false;
		}
	}
	
	queue<ii> q;
	q.push({1,1});
	while (!q.empty()){
		ii curr = q.front(); q.pop();
		if (visited[curr])	continue;
		visited[curr] = true;

		for (int k = 0; k < 4; ++k){
			q.push({g[curr.first][k], h[curr.second][k]});
		}

		/*
		for (auto& next : gh[curr]){
			q.push(next);
		}
		*/
	}

	bool in1 = false, in2 = true;
	for (int i = 0; i <= n; ++i){
		if (visited[{n,i}])	in1 = true;
	}
	for (int i = 0; i < n; ++i){
		if (visited[{n,i}])	in2 = false;
	}

	if (!in1){
		cout << "Impossible" << endl;
	}
	else if (in2){
		cout << "Yes" << endl;
	}
	else{
		cout << "No" << endl;
	}

	return 0;
}
