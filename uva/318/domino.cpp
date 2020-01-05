#include <iostream>
#include <queue>
#include <vector>
#include <iomanip>
using namespace std;

const int INF = 200000005;
typedef pair<int,int> pii;
typedef vector<vector<pii>> graph;
int n, m;

void dijkstra(graph& g, int s){
	vector<int> dist(n, INF);
	vector<int> par(n, -1);

	for (int i = 1; i <= n; ++i){
		dist[i] = INF;
		par[i] = -1;
	}

	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push(make_pair(0, s));
	dist[s] = 0;
	par[s] = s;

	int maxDist = 0;
	int dom = s;
	while (!pq.empty()){
		int u = pq.top().second;
		pq.pop();

		for (pii it : g[u]){
			int v = it.first;
			int w = it.second;
			if (dist[u] + w < dist[v]){
				dist[v] = dist[u] + w;
				par[v] = u;
				pq.push({dist[v], v});
				if (dist[v] > maxDist){
					maxDist = dist[v];
					dom = v;
				}
			}
		}
	}

	cout << fixed << setprecision(1);
	cout << (float)maxDist << endl;
	cout << dom << endl;
}

int main(){
	int t = 1;
	while (cin >> n >> m){
		if (n == 0 and m == 0)	break;
		graph g(n+1);
		for (int i = 0; i < m; ++i){
			int u, v, l;
			cin >> u >> v >> l;
			g[u].push_back({v, l});
			g[v].push_back({u, l});
		}
		cout << "System #" << t << endl;
		dijkstra(g, 1);
		t++;
	}

	return 0;
}
