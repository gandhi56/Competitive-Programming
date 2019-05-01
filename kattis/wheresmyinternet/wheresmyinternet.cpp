#include <iostream>
#include <vector>
using namespace std;

int find(int* uf, int u){
	if (uf[u] != u)	uf[u] = find(uf, uf[u]);
	return uf[u];
}

bool merge(int* uf, int u, int v){
	u = find(uf, u);
	v = find(uf, v);
	if (u == v)	return false;
	uf[u] = v;
	return true;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;

	int uf[n+1];
	for (int i = 1; i <= n; ++i)	uf[i] = i;

	while (m--){
		int u, v;
		cin >> u >> v;
		merge(uf, u, v);
	}

	vector<int> disconnected;
	int u = find(uf, 1);
	for (int i = 2; i <= n; ++i){
		if (find(uf, i) != find(uf, 1))	disconnected.push_back(i);
	}

	if (disconnected.size() == 0){
		cout << "Connected" << endl;
	}
	else{
		for (auto x : disconnected)	cout << x << endl;
	}

	return 0;
}
