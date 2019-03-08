#include <iostream>
#include <vector>
using namespace std;
const int inf = 1e9;

int n, m, s, t;
typedef vector< vector<int> > vii;
typedef vector<int> vi;

vii cap, flow;
vi h, excess;

void push(int u, int v){
	int d = min(excess[u], cap[u][v] - flow[u][v]);
	flow[u][v] += d;
	flow[v][u] -= d;
	excess[u] -= d;
	excess[v] += d;
}

void relabel(int u){
	int d = inf;
	for (int i =0 ; i < n; ++i){
		if (cap[u][i] - flow[u][i] > 0){
			d = min(d, h[i]);
		}
	}
	if (d < inf)
		h[u] = d + 1;
}

void find_max_height(vi& maxHeight){
	for (int i = 0; i < n; ++i){
		if (i != s and i != t and excess[i] > 0){
			if (!maxHeight.empty() and h[i] > h[maxHeight[0]]){
				maxHeight.clear();
			}
			if (maxHeight.empty() or h[i] == h[maxHeight[0]]){
				maxHeight.push_back(i);
			}
		}
	}
}

void maxFlow(){
	h.assign(n, 0);
	h[s] = n;
	flow.assign(n, vector<int>(n, 0));
	excess.assign(n, 0);
	excess[s] = inf;
	for (int i =0 ; i < n; ++i){
		if (i != s)	push(s, i);
	}
	while (1){
		vi curr;
		find_max_height(curr);
		if (curr.empty())	break;
		for (int i : curr){
			bool pushed = false;
			for (int j = 0; j < n and excess[i]; ++j){
				if (cap[i][j] - flow[i][j] > 0 and h[i] == h[j] + 1){
					push(i, j);
					pushed = true;
				}
			}
			if (!pushed){
				relabel(i);
				break;
			}
		}
	}

	int maxFlow =0 ;
	for (int i =0 ; i < n; ++i){
		maxFlow += flow[0][i];
	}

	cout << n << " " << maxFlow << " ";
	// count edges
	int edges = 0;
	for (int i =0 ; i < n; ++i){
		for (int j = i + 1; j < n; ++j){
			if (flow[i][j])	edges++;
		}
	}
	cout << edges << endl;

	for (int i =0 ; i < n; ++i){
		for (int j = i + 1; j < n; ++j){
			if (flow[i][j]){
				cout << i << " " << j << " " << flow[i][j] << endl;
			}
		}
	}

}


int main(){
	cin >> n >> m >> s >> t;

	h.resize(n);
	excess.resize(n);
	cap.resize(n);
	flow.resize(n);
	for (int i =0 ; i < n; ++i){
		cap[i].resize(n);
		flow[i].resize(n);
	}
	for (int i =0 ; i < m; ++i){
		int u, v, c;
		cin >> u >> v >> c;
		cap[u][v] = c;
	}

	maxFlow();
	return 0;
}
