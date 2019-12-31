#include <iostream>
#include <vector>
#include <stack>
#include <cstdio>
using namespace std;

typedef vector< vector<int> > graph;

void eulerpath(graph& g, vector<int>& euler, int start){
	stack<int> s;
	s.push(start);
	while (!s.empty()){
		int u = s.top();
		if (g[u].empty()){
			euler.push_back(u);
			s.pop();
		}
		else{
			s.push(g[u].back());
			g[u].pop_back();
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;

	while (cin >> n >> m){
		if (n == 0 and m == 0)	break;
		graph g(n);
		vector<int> indeg(n, 0), outdeg(n, 0);
		for (int i =0 ; i < m; ++i){
			int u, v;
			cin >> u >> v;
			g[u].push_back(v);
			indeg[v]++;
			outdeg[u]++;
		}

		bool exists = true;
		bool k1 = 0;
		bool k2 = 0;
		int start = 0;
		for (int i = 0; i < n; ++i){
			if (indeg[i] == outdeg[i])	continue;
			else if (indeg[i] + 1 == outdeg[i]){
				if (k1)	exists = false;
				k1 = true;
				start = i;
			}
			else if (indeg[i] == outdeg[i] + 1){
				if (k2)	exists = false;
				k2 = true;
			}
			else{
				exists = false;
			}
		}

		if (!exists){
			cout << "Impossible" << endl;
			continue;
		}

		if (!k1){
			while (outdeg[start] == 0)	start++;
		}

		vector<int> euler;
		eulerpath(g, euler, start);
		if (euler.size() != m + 1){
			cout << "Impossible" << endl;
		}
		else{
			for (int i = euler.size()-1; i >= 0; --i){
				cout << euler[i] << " ";
			}
			cout << endl;
		}
	}

	return 0;
}
