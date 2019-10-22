#include <bits/stdc++.h>
using namespace std;

struct node{
	int u, indeg = 0;
	vector<int> pred;
};

typedef pair<int,int> ii;

int main(){
	int n;
	cin >> n;

	vector<node> g(n);
	for (int i = 0; i < n; ++i){
		int d;
		cin >> g[i].u >> d;
		while (d--){
			int di;
			cin >> di;
			g[i].pred.push_back(di - 1);
			++g[di-1].indeg;
		}
	}

	priority_queue<ii> pq;
	for (int i = 0; i < n; ++i){
		if (g[i].indeg == 0)
			pq.push({-g[i].u, i});
	}

	int w, u, m = n-1, ans = 0;
	while (!pq.empty()){
		tie(w, u) = pq.top(); pq.pop();
		w *= -1;
		ans = max(ans, w+m--);
		for (auto& v : g[u].pred){
			if (--g[v].indeg == 0){
				pq.push({-g[v].u, v});
			}
		}
	}

	cout << ans << endl;

	return 0;
}
