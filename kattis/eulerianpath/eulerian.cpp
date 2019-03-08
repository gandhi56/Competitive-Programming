#include <iostream>
#include <vector>
#include <cstring>
#include <stack>
using namespace std;

typedef vector< vector<int> > graph;

int n, m;
int deg[10010];

bool eulerian(graph& g){
	int count = 0;
	for (int u = 0; u < n; ++u){
		if (deg[u] % 2)	count++;
		if (count > 2)	return false;
	}
	return (count == 2);
}

int main(){
	while (cin >> n >> m){
		if (n == 0 and m == 0)	break;
		memset(deg, 0, sizeof(deg));

		vector< vector<bool> > g(n, vector<bool>(n, false));
		int u, v;
		for (int i = 0; i < m; ++i){
			cin >> u >> v;
			g[u][v] = true;
		}
		
		vector<int> deg(n);
		for (int i =0 ; i < n; ++i){
			for (int j =0; j < n; ++j){
				deg[i] += (g[i][j] == true);
			}
		}

		int first = 0;
		while (!deg[first])	++first;

		int v1 = -1, v2 = -1;
		bool bad = false;
		for (int i = 0; i < n; ++i){
			if (deg[i] & 1){
				if (v1 == -1){
					v1 = i;
				}
				else if (v2 == -1){
					v2 = i;
				}
				else{
					bad = true;
				}
			}
		}

		if (v1 != -1){
			g[v1][v2] = true;
			g[v2][v1] = true;
		}

		stack<int> s;
		s.push(first);
		vector<int> res;
		while (!s.empty()){
			int v = s.top();
			int i;
			for (i = 0; i < n; ++i){
				if (g[v][i])	break;
			}
			if (i == n){
				res.push_back(v);
				s.pop();
			}
			else{
				g[v][i] = false;
				g[i][v] = false;
				s.push(i);
			}
		}

		if (v1 == -1){
			for (int i = 0; i+1 < res.size(); ++i){
				if ((res[i] == v1 and res[i+1] == v2) or 
					(res[i] == v2 and res[i+1] == v1)){
					vector<int> res2;
					for (int j = i + 1; j < res.size(); ++j){
						res2.push_back(res[j]);
					}
					for (int j = 1; j <= i; ++j){
						res2.push_back(res[j]);
					}
					res = res2;
					break;
				}
			}
		}

		for (int i =0 ; i < n; ++i){
			for (int j = 0; j < n; ++j){
				if (g[i][j])	bad = true;
			}
		}

		if (bad){
			cout << "impossible" << endl;
		}
		else{
			for (int x : res)	cout << x << " ";
			cout << endl;
		}
	}

	return 0;
}
