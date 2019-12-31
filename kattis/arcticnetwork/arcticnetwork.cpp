#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;

typedef pair<int,int> ii;

double sq(int x){	return x*x;	}

double dist(ii a, ii b){
	return sqrt( sq(a.first-b.first) + sq(a.second-b.second) );
}

bool cmp(pair<ii, double> a, pair<ii, double> b){
	return a.second < b.second;
}

int find(int* uf, int u){
	if (uf[u] != u)
		return uf[u] = find(uf, uf[u]);
	return uf[u];
}

bool merge(int* uf, int u, int v){
	u = find(uf, u);
	v = find(uf, v);
	if (u == v)	return false;
	uf[u] = v;
	return true;
}

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cout << fixed << setprecision(2);
	int t;
	cin >> t;

	while (t--){
		int s, p;
		cin >> s >> p;

		vector<ii> pos;
		for (int i =0 ; i < p; ++i){
			int x, y;
			cin >> x >> y;
			pos.push_back({x, y});
		}

		vector<pair<ii, double>> edges;
		for (int i = 0; i < p; ++i){
			for (int j = i + 1; j < p; ++j){
				edges.push_back({{i,j}, dist(pos[i], pos[j])});
			}
		}

		sort(edges.begin(), edges.end(), cmp);


		int uf[p];
		for (int i = 0; i < p; ++i)	uf[i] = i;

		double cost = 0.0;
		vector<pair<ii, double>> tree;
		for (auto e : edges){
			if (merge(uf, e.first.first, e.first.second)){
				tree.push_back(e);
			}
		}

		for (int i = 1; i < s; ++i)	tree.pop_back();
		cout << tree.back().second << endl;

	}

	return 0;
}
