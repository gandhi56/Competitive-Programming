#include <bits/stdc++.h>
using namespace std;

#define MOD 9901
#define MAXN 301

int adj[MAXN];
int n, k;

int dfs(int u, int depth, int mask){
	if (depth == n-1 and (adj[u]&1) == 0){
		return 1;
	}
	else if (depth == n-1){
		return 0;
	}

	int count = 0;
	for (int i = 0; i < n; i++){
		if (u != i and (adj[u]&(1<<i))==0 and (mask&(1<<i))){
			count = (count + dfs(i, depth+1, mask & ~(1<<i))) % MOD;
		}
	}
	return count;
}

int main(){
	int t;
	cin >> t;

	int tt = 1;
	while (t--){
		memset(adj, 0, sizeof(adj));

		cin >> n >> k;

		while (k--){
			int u, v;
			cin >> u >> v;
			u--; v--;
			adj[u] |= (1<<v);
			adj[v] |= (1<<u);
		}
		cout << "Case #" << tt << ": " << (dfs(0, 0, (1<<n)-2) * 4951LL) % MOD<< endl;
		tt++;
	}

	return 0;
}
