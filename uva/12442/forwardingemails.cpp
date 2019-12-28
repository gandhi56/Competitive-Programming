#include <iostream>
#include <cstring>
using namespace std;

void dfs(int next[], int u, bool* visited){
	visited[u] = true;
	if (!visited[next[u]])	dfs(next, next[u], visited);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	for (int tt = 1; tt <= t; ++tt){
		int n;
		cin >> n;

		int next[n+1];
		for (int i = 0; i < n; ++i){
			int u, v;
			cin >> u >> v;

			next[u] = v;
		}

		int count = 0;
		int ans = 0;
		int u = 1;
		bool visited[n+1];
		int checked[n+1];
		memset(checked, 0, sizeof(checked));
		while (u <= n){
			memset(visited, false, sizeof(visited));
			dfs(next, u, visited);
			
			int c =0 ;
			for (int i = 1; i <= n; ++i){
				c += (visited[i]);
				if (visited[i])	checked[i] = u;
			}
			if (c > count){
				count = c;
				ans = u;
			}
			while (checked[u])	u++;
		}
		cout << "Case " << tt << ": " << ans << endl;
	}
	return 0;
}
