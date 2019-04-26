#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
using namespace std;

typedef vector<int> vi;
typedef vector< vector<int> > vii;

int dtime;

bool scc(vii& g, int u, vi& low, vi& disc, bool* onstack, stack<int>& s){
	disc[u] = dtime;
	low[u] = dtime;
	dtime++;
	s.push(u);
	onstack[u] = true;
	for (auto v : g[u]){
		if (disc[v] == -1){
			scc(g, v, low, disc, onstack, s);
			low[u] = min(low[u], low[v]);
		}
		else if (onstack[v]){
			low[u] = min(low[u], disc[v]);
		}
	}
	if (low[u] == disc[u]){
		while (1){
			int v = s.top();
			s.pop();
			if (u == v)	break;
			onstack[v] = false;
		}
	}
	return true;
}

void tarjanscc(vii g){
	vi disc(g.size(), -1);
	vi low(g.size(), -1);
	bool onstack[g.size()];
	memset(onstack, false, sizeof(onstack));
	stack<int> s;


	int count = 0;
	for (int u = 0; u < g.size(); ++u){
		if (disc[u] == -1){
			dtime = 0;
			scc(g, u, low, disc, onstack, s);
			count++;
		}
	}
	cout << count << endl;
}

int main(){
	int t;
	cin >> t;

	while (t--){
		int n, m;
		cin >> n >> m;
		
		vii g(n);
		while (m--){
			int u, v;
			cin >> u >> v;
			u--;v--;
			g[u].push_back(v);
		}
		tarjanscc(g);
	}

	return 0;
}
