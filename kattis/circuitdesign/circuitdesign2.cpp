
#define MAXN 1024
#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef vector< vector<int> > graph;
const ld PI = acos(-1.0);

int n;
graph g;
ld x[MAXN];
ld y[MAXN];
int angleperdepth[MAXN];

void solve(int u, int d = 0, int p = -1){
	bool first = true;
	for (auto v : g[u]){
		if (v == p)	continue;
		if (first)	first = false;
		else		angleperdepth[d]++;
		ld w = angleperdepth[d] * PI * 0.5 / MAXN;
		ld dx = sin(w), dy = cos(w);
		ld dist = sqrt( dx*dx + dy*dy );
		x[v] = x[u] + dx / dist;
		y[v] = y[u] + dy / dist;
		solve(v, d+1, u);
	}
}

int main(){
	cin >> n;
	g.resize(n);
	for (int i = 0; i < n; ++i)	angleperdepth[i] = 1;
	for (int i = 1; i < n; ++i){
		int a, b;
		cin >> a >> b;
		g[--a].push_back(--b);
		g[b].push_back(a);
	}

	x[0] = y[0] = 0.0;
	solve(0);
	cout << fixed << setprecision(12);
	for (int i = 0; i < n; ++i){
		cout << x[i] << " " << y[i] << endl;
	}
	return 0;
}
