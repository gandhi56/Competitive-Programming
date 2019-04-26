#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
using namespace std;

#define maxn 20005

typedef vector<int> vi;
typedef vector< vi > vii;

int n, m;
int foundat = 1;
vii g;
vi disc, low;
bool onstack[maxn];

bool tarjan(int u){
	static stack<int> s;
	disc[u] = low[u] = foundat++;
	s.push(u);
	onstack[u] = true;
	for (auto i : g[u]){
		if (disc[i] == -1){
			tarjan(i);
			low[u] = min(low[u], low[i]);
		}
		else if (onstack[i]){
			low[u] = min(low[u], low[i]);
		}
	}

	if (disc[u] == low[u]){
		while (1){
			int v = s.top();
			s.pop();
			onstack[v] = false;
			if (u == v)	break;
		}
		return true;
	}
	return false;
}

int main(){
	int t;
	cin >> t;

	while (t--){
		cin >> n >> m;

		memset(onstack, false, sizeof(onstack));
		g.clear(); g.resize(n+1);
		disc.clear(); disc.resize(n+1, -1);
		low.clear(); low.resize(n+1);
	
		while (m--){
			int u, v;
			cin >> u >> v;
			g[u].push_back(v);
		}

		int count = 0;
		for (int i = 1; i <= n; ++i){
			if (disc[i] == -1){
				if (tarjan(i))	count++;
			}
		}
		cout << count << endl;
	}

	return 0;
}
