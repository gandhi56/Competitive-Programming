#include <iostream>
using namespace std;

int n, m;

int find(int uf[], int u){
	return (uf[u] == u) ? u : (uf[u] = find(uf, uf[u]));
}

bool merge(int uf[], int rk[], int u, int v){
	int uu = find(uf, u);
	int vv = find(uf, v);
	if (uu == vv)	return false;
	if (rk[uu] >= rk[vv]){
		uf[vv] = uu;
		rk[uu] += rk[vv];
		return true;
	}
	else if (rk[uu] < rk[vv]){
		uf[uu] = vv;
		rk[vv] += rk[uu];
		return true;
	}
}

void show(int uf[]){
	for (int i = 1; i <= n; ++i){
		cout << i << " - " << uf[i] << endl;
	}
}

int main(){
	cin >> n >> m;

	int uf[n+1];
	int rk[n+1];

	vector< vector<int> > grp(n+1);

	for (int i= 0; i < n+1; ++i){
		uf[i] = i;
		rk[i] = 1;
	}

	merge(uf, rk, 1, 2);
	for (int i = 0; i < m; ++i){
		int k;
		cin >> k;
		if (k == 0)	continue;
		k--;

		int u;
		cin >> u;

		grp[u].push_back(i);
		while (k--){
			int v;
			cin >> v;
			grp[v].push_back(i);
			merge(uf, rk, u, v);
		}
	}

	for (int i = 1; i <= n; ++i){
		cout << rk[uf[i]] << " ";
	}
	cout << endl;

	return 0;
}
