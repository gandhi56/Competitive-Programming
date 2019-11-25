#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> parent, rnk;

void make_set(int v){
	parent[v] = v;
	rnk[v] = 0;
}

int find_set(int v){
	if (v == parent[v])	return v;
	return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b){
	a = find_set(a);
	b = find_set(b);
	if (a !=  b){
		if (rnk[a] < rnk[b]){
			swap(a,b);
		}
		parent[b] = a;
		if (rnk[a] == rnk[b])
			rnk[a]++;
	}
}

struct edge{
	int u, v, w;
	bool operator<(edge const& e){
		return w < e.w;
	}
};

int main(){
	int n;
	cin >> n;

	vector<edge> edges;

	for (int i = 0; i < n; ++i){
		for (int j =0 ; j < n; ++j){
			int w;
			cin >> w;
			if (j <= i)	continue;
			edge e;
			e.u = i;
			e.v = j;
			e.w = w;
			edges.push_back(e);
		}
	}

	int cost = 0;
	vector<edge> result;
	parent.resize(n);
	rnk.resize(n);
	for (int i =0 ; i < n; ++i)	make_set(i);

	sort(edges.begin(), edges.end());

	for (edge e : edges){
		if (find_set(e.u) != find_set(e.v)){
			cost += e.w;
			result.push_back(e);
			union_sets(e.u, e.v);
		}
	}

	for (edge e : result){
		cout << e.u+1 << " " << e.v+1 << endl;
	}

	return 0;
}
