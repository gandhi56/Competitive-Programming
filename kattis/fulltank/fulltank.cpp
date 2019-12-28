#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int,int> ii;
typedef vector< vector< ii > > graph;
int p[200];
int dist[1000][200];

void solve(graph& g, int s, int e, int c){
	priority_queue< ii, vector<ii>, greater<ii> > pq;
	pq.push(ii(0, s));

	while (!pq.empty()){
		ii top = pq.top();pq.pop();
		int d = top.first;
		int u = top.second;
		if (d == dist[s][u]){
			for (auto& it : g[u]){
				int v = it.first;
				int w = it.second;
				if (dist[s][u] + w < dist[s][v]){
					dist[s][v] = dist[s][u] + w;
					pq.push(ii(dist[s][v], v));
				}
			}
		}
	}

	cout << "dist to e:" << dist[s][e] << endl;

}

int main(){
	int n, m;
	cin >> n >> m;
	for (int i =0 ; i < n; ++i)	cin >> p[i];
	graph g(n);
	for (int i = 0; i < m; ++i){
		int u, v, w;
		cin >> u >> v >> w;
		g[u].push_back({w, v});
		g[v].push_back({w, u});
	}

	int q;
	cin >> q;


	while (q--){
		int s, e, c;
		cin >> s >> e >> c;
		solve(g, s, e, c);
	}

	return 0;
}
