
#define MAXN 1001

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <bitset>
using namespace std;

typedef vector< vector<int> > graph;
typedef long double lld;
typedef pair<lld, lld> point;

int n;
point pos[MAXN];
graph g;
int deg[MAXN];
bitset<MAXN> assigned;

int getMaxVertex(){
	int* maxdeg = max_element(deg, deg + n);
	for (int i = 0; i < n; ++i){
		if (deg[i] == *maxdeg)
			return i;
	}
}

void solve2(int u, point offset){
	// semi circle case
	// assume u is already placed
	lld theta = 0.0;
	lld incAngle = M_PI / deg[u];
	assigned.set(u);
	for (auto& v : g[u]){
		if (assigned.test(v))	continue;
		pos[v] = {offset.first + cos(theta), offset.second + sin(theta)};
		assigned.set(v);
		theta += incAngle;
		solve2(v, pos[v]);
	}
}

void solve(point center){
	int u = getMaxVertex();
	pos[u] = center;
	assigned.set(u);
	lld theta = 0.0;
	lld incAngle = (2.0 * M_PI) / deg[u];
	for (auto& v : g[u]){
		pos[v] = {cos(theta), sin(theta)};
		theta += incAngle;
		solve2(v, pos[v]);
	}
}


int main (){

	assigned.reset();

	cin >> n;
	g.resize(n);
	memset(deg, 0, sizeof(deg));
	for (int i = 0; i < n-1; ++i){
		int a, b;
		cin >> a >> b;
		g[--a].push_back(--b);
		g[b].push_back(a);
		deg[a]++;
		deg[b]++;
	}

	point center = {0.0, 0.0};
	solve(center);

	cout << fixed << setprecision(12);

	for (int i = 0; i < n; ++i){
		cout << pos[i].first << " " << pos[i].second << endl;
	}

	return 0;
}
