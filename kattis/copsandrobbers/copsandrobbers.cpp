#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <limits>
#include <queue>

#define MAXN 30;
#define MAXC 26
#define MAXCOST 100000
#define INF 1000000000

using namespace std;

struct FlowEdge{
	FlowEdge():	dst(0), src(0), cap(0), flow(0){}
	FlowEdge(int src, int dst, int cap): src(src), dst(dst), cap(cap), flow(0)	{}
	int dst, src, cap;
	int flow;
	FlowEdge* redge;
};

typedef vector< list<FlowEdge> > AdjFlowGraph;
typedef vector< list<FlowEdge> >::iterator NodeIterator;
typedef vector< list<FlowEdge> >::const_iterator ConstNodeIterator;
typedef list<FlowEdge>::iterator EdgeIterator;
typedef list<FlowEdge>::const_iterator ConstEdgeIterator;

struct FlowGraph{
	FlowGraph(int n) : 	graph(n, list<FlowEdge>())	{}
	void reserve(int n){
		graph.reserve(n);
	}

	void addEdge(int src, int dst, int cap){
		graph[src].push_back(FlowEdge(src, dst, cap));
		FlowEdge* e1 = &graph[src].back();
		graph[dst].push_back(FlowEdge(dst, src, 0));
		FlowEdge* e2 = &graph[dst].back();
		e1->redge = e2;
		e2->redge = e1;
	}
	AdjFlowGraph graph;
};

int edmondsKarp(FlowGraph& FG, int source, int sink){
	while(1){
		queue<int> visitQueue;
		vector<bool> visited(FG.graph.size(), false);
		vector< FlowEdge* > pathTo(FG.graph.size(), NULL);
		visitQueue.push(source);
		visited[source] = true;
		int cur;

		while (1){
			if (visitQueue.empty()){
				int flow = 0;
				for (ConstEdgeIterator it = FG.graph[source].begin(); it != FG.graph[source].end(); ++it){
					flow += it->flow;
				}
				return flow;
			}
			cur = visitQueue.front();
			visitQueue.pop();
			if (cur == sink)
				break;

			for (EdgeIterator it = FG.graph[cur].begin(); it!=FG.graph[cur].end(); ++it){
				if (visited[it->dst] or it->flow >= it->cap)
					continue;

				visitQueue.push(it->dst);
				visited[it->dst] = true;
				pathTo[it->dst] = &*it;
			}
		}

		int capacity = numeric_limits<int>::max();
		for (int loc = cur; loc != source; loc = pathTo[loc]->src){
			capacity = min(pathTo[loc]->cap - pathTo[loc]->flow, capacity);
		}

		for (int loc = cur; loc != source; loc = pathTo[loc]->src){
			pathTo[loc]->flow += capacity;
			pathTo[loc]->redge->flow -= capacity;
		}
	}
}

int main(){
/*
	int n, m, s, t;
	cin >> n >> m >> s >> t;

	FlowGraph fg(n);
	while (m--){
		int u, v, c;
		cin >> u >> v >> c;
		fg.addEdge(u, v, c);
	}

	cout << n << " " << edmondsKarp(fg, s, t) << " ";

	int edges = 0;
	for (int cur = 0; cur < n; ++cur){
		for (EdgeIterator it = fg.graph[cur].begin(); it != fg.graph[cur].end(); ++it){
			if (it->flow > 0)
				edges++;
		}
	}
	cout << edges << endl;

	for (int cur = 0; cur < n; ++cur){
		for (EdgeIterator it = fg.graph[cur].begin(); it != fg.graph[cur].end(); ++it){
			if (it->flow > 0)
				cout << it->src << " " << it->dst << " " << it->flow << endl;
		}
	}
*/


	const int dx[] = {1, 0, -1,  0};
	const int dy[] = {0, 1,  0, -1};

	int n, m, c;
	cin >> n >> m >> c;

	string grid[n];
	int cost[c];
	for (int i= 0; i < n; ++i)	cin >> grid[i];
	for (int i = 0; i < c; ++i)	cin >> cost[i];

	int source = -1;
	int sink = n*m*2;

	FlowGraph fg(2*n*m+1);

	for (int i = 0; i < m; ++i){
		for (int j = 0; j < n; ++j){
			if (grid[i][j] == 'B'){
				source = i*n + n*m + j;
			}
			else if (grid[i][j] == '.'){
				// add edge here
				fg.addEdge(i*n+j, i*n+j+n*m, INF);
			}
			else{
				// add edge
				fg.addEdge(i*n+j, i*n+j+n*m, cost[grid[i][j] - 'a']);
			}

			for (int k = 0; k < 4; ++k){
				int x = i + dx[k];
				int y = j + dy[k];
				if (x >= 0 and y >= 0 and x < m and y < n){
					fg.addEdge(i*n+j+n*m, x*n+y, INF);
				}
				else{
					fg.addEdge(i*n+j+n*m, sink, INF);
				}
			}
		}
	}


	cout << edmondsKarp(fg, source, sink) << endl;
	return 0;
}



















