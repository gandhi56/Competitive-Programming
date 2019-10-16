
#define MAXN 300001
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector< vector<int> > graph;

int n;
int par[MAXN];
ll lflow[MAXN];
ll flow[MAXN];
ll oflow[MAXN];

int main(){
	cin >> n;
	graph g(n);

	// input graph
	for (int i = 1; i < n; ++i){
		int u;
		cin >> u;--u;
		par[i] = u;
		g[u].push_back(i);
	}
	par[0] = -1;

	// input flow
	for (int i = 0; i < n; ++i){
		cin >> flow[i];
		oflow[i] = flow[i];
		lflow[i] = 0LL;
	}

	// set min flow for each node
	for (int i = n-1; i >= 0; --i){
		ll tot = 0;
		for (auto& x : g[i])
			tot += lflow[x];
		lflow[i] = max((ll)1, flow[i]);
		lflow[i] = max(lflow[i], tot);
	}

	// bottom up traversal
	for (int i = n-1; i >= 0; --i){
		if (g[i].size() == 0)	continue;
		ll tot =0;
		bool ok = true;
		for (auto& x : g[i]){
			if (flow[x] == 0){
				ok = false;
				break;
			}
			tot += flow[x];
		}
		if (ok){
			flow[i] = tot;
			lflow[i] = tot;
		}
	}
	

	// top down traversal
	for (int i = 0; i < n; ++i){
		// compute remaining flow
		ll tot = 0;
		for (auto& x : g[i]){
			tot += lflow[x];
		}
		ll rem = flow[i] - tot;

		// count the number of children whose flow is still unknown
		int unknownCount = 0;
		for (auto& x : g[i]){
			if (flow[x] <= 0)
				unknownCount++;
		}
		
		if (rem>0 and unknownCount >= 2){
			flow[i] = 0;
		}
		for (auto& x : g[i]){
			if (flow[x] == 0)
				flow[x] = lflow[x] + rem;
		}
	}

	for (int i = 0; i < n; ++i){
		if ((oflow[i] > 0 and oflow[i] != flow[i]) or flow[i] < 1){
			cout << "impossible" << endl;
			return 0;
		}
	}
	for (int i = 0; i < n; ++i)	cout << flow[i] << endl;
	return 0;
}
