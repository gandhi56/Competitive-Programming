#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <iomanip>
using namespace std;

#define INF 999999

typedef pair<int,int> pii;
typedef vector< vector< pii > > graph;

void dijkstra(graph& g, int s){
	int dist[g.size()];
	for (int i = 0; i < g.size(); ++i)	dist[i] = -1;
	priority_queue< pii, vector< pii >, greater< pii > > pq;
	pq.push(make_pair(0,s));
	dist[s] = 0;
	
	int curr = 0;
	
	while (!pq.empty()){
		pii edge = pq.top();
		pq.pop();

		int u = edge.second;

		for (pii& next : g[u]){
			int v = next.first;
			int w = next.second;
			if (dist[v] == -1 or (dist[u] + w < dist[v])){
				dist[v] = dist[u] + w;
				curr = dist[v];
				pq.push(make_pair(dist[v], v));
			}
		}
	}

	cout << fixed << setprecision(1) << (float)curr << endl;
}

int main(){
	int n, m;
	int t = 1;
	while (cin >> n >> m){
		if (n == 0 and m == 0)	break;
		graph g(n+1);
		for (int i =0 ; i < m; ++i){
			int a, b, l;
			cin >> a >> b >> l;
			g[a].push_back({b, l});
			g[b].push_back({a, l});
		}
		cout << "System #" << t << endl;
		dijkstra(g, 1);
		t++;
	}
	return 0;
}
