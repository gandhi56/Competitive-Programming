#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <limits>
#include <queue>
#include <cmath>

#define EPS 0.001

using namespace std;

// Flow graph implementation, including reverse-edge pointers.
struct FlowEdge {
	FlowEdge() : dst(0), src(0), cap(0.0), flow(0.0) {}
	FlowEdge(int src, int dst, int cap) : src(src), dst(dst), cap(cap), flow(0) {}
	int dst, src;
	int cap;
	int flow;
	FlowEdge *redge;
};

// Typedefs for readability.
typedef vector<list<FlowEdge> > AdjFlowGraph;
typedef vector<list<FlowEdge> >::iterator NodeIterator;
typedef vector<list<FlowEdge> >::const_iterator ConstNodeIterator;
typedef list<FlowEdge>::iterator EdgeIterator;
typedef list<FlowEdge>::const_iterator ConstEdgeIterator;
typedef pair<double, double> dd;

struct FlowGraph {
	FlowGraph(int N) : graph(N, list<FlowEdge>()) {}
	void reserve(int N) { graph.reserve(N); }
	void addEdge(int src, int dst, int cap){
		graph[src].push_back(FlowEdge(src, dst, cap));
		FlowEdge *e1 = &graph[src].back();
		graph[dst].push_back(FlowEdge(dst, src, 0));
		FlowEdge *e2 = &graph[dst].back();
		e1->redge = e2;
		e2->redge = e1;
	}
	AdjFlowGraph graph;
};

int EdmondsKarp(FlowGraph& FG, int source, int sink){
	while (1) {
		queue<int> visitQueue;
		vector<bool> visited(FG.graph.size(), false);
		vector<FlowEdge *> pathTo(FG.graph.size(), NULL);
		visitQueue.push(source);
		visited[source] = true;
		
		int cur;


		while (1) {
			if (visitQueue.empty()) {
				int flow = 0;
				for (ConstEdgeIterator it = FG.graph[source].begin();
						it != FG.graph[source].end(); ++it) {
					flow += it->flow;
				}
				return flow;
			}
			cur = visitQueue.front();
			visitQueue.pop();
			if (cur == sink) break;
			for (EdgeIterator it = FG.graph[cur].begin();it != FG.graph[cur].end(); ++it) {
				if (visited[it->dst] || it->flow >= it->cap) continue;
				visitQueue.push(it->dst);
				visited[it->dst] = true;
				pathTo[it->dst] = &*it;
			}
		}
		int capacity = numeric_limits<int>::max();
		for (int loc = cur; loc != source; loc = pathTo[loc]->src) {
			capacity = min(pathTo[loc]->cap - pathTo[loc]->flow, capacity);
		}
		for (int loc = cur; loc != source; loc = pathTo[loc]->src) {
			pathTo[loc]->flow += capacity;
			pathTo[loc]->redge->flow -= capacity;
		}
	}
}

inline double SQ(double x){
	return x*x;
}

inline double getDist(dd a, dd b){
	return sqrt( SQ(a.first-b.first) + SQ(a.second-b.second) );
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m; 
	double s, v;
	while (cin >> n >> m >> s >> v){
		vector< dd > gophers, holes;
		for (int i = 0; i < n; ++i){
			double x, y;
			cin >> x >> y;
			gophers.push_back({x, y});
		}

		for (int i =0 ; i < m; ++i){
			double x, y;
			cin >> x >> y;
			holes.push_back({x, y});
		}

		// 0..n-1 - gophers
		// n..n+m-1 - holes
		// n+m - sink
		// n+m+1 - source
		FlowGraph fg(gophers.size()+holes.size()+2);
		const int source = n+m+1;
		const int sink = n+m;

		for (int i = 0; i < n; ++i){
			for (int j = 0; j < m; ++j){
				double dist = getDist(gophers[i], holes[j]);
				double time = dist / v;
				if (time <= s)
					fg.addEdge(i, n+j, 1);
			}
		}
		for (int i = 0; i < gophers.size(); ++i){
			fg.addEdge(source, i, 1);
		}
		for (int i = 0; i < holes.size(); ++i){
			fg.addEdge(gophers.size()+i, sink, 1);
		}

		int count = EdmondsKarp(fg, source, sink);

		cout << gophers.size() - count << endl;
	
	}

	return 0;
}


