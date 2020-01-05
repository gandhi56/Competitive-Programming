#include <bits/stdc++.h>
using namespace std;

typedef pair<double, double> dd;
typedef pair<int,int> ii;

vector<int> par, rk;

double sqr(double a){
	return a*a;
}

double dist(dd a, dd b){
	return sqrt( sqr(a.first - b.first) + sqr(a.second - b.second) );
}

void make_set(int v){
	par[v] = v;
	rk[v] = 0;
}

int find_set(int v){
	if (v == par[v])
		return v;
	return par[v] = find_set(par[v]);
}

void union_sets(int a, int b){
	a = find_set(a);
	b = find_set(b);
	if (a != b){
		if (rk[a] < rk[b]){
			swap(a, b);
		}
		par[b] = a;
		if (rk[a] == rk[b])
			rk[a]++;
	}
}

int main(){

	int n, e, p;
	cin >> n >> e >> p;

	par.resize(n);
	rk.resize(n);


	for (int i = 0; i < n; ++i)
		make_set(i);
	// p = number of edges already in place

	vector<dd> points;
	for (int i = 0; i < n; ++i){
		double x, y;
		cin >> x >> y;
		points.push_back({x,y});
	}


	// input edges
	vector<pair<double, ii>> edges;
	for (int i =0 ; i < p; ++i){
		int u, v;
		cin >> u >> v;

		double dis = dist(points[u-1], points[v-1]);
		union_sets(u-1, v-1);
	}

	for (int i = 0; i < e; ++i){
		for (int j = i + 1; j < e; ++j){
			union_sets(i, j);
		}
	}

	// construct complete graph
	for (int i = 0; i < n; ++i){
		for (int j = i + 1; j < n; ++j){
			if (find_set(i) != find_set(j)){
				edges.push_back( { dist(points[i], points[j]), {i, j} } );
			}
		}
	}


	double cost = 0.0;
	sort(edges.begin(), edges.end());
	for (auto e : edges){
		if (find_set(e.second.first) != find_set(e.second.second)){
			cost += e.first;
			union_sets(e.second.first, e.second.second);
		}
	}
	cout << fixed << setprecision(5);
	cout << cost << endl;

	return 0;
}
