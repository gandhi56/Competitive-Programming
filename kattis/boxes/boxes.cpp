#include <iostream>
#include <vector>
using namespace std;

typedef vector< vector<int> > ii;

int start[200001];
int finish[200001];
int count[200001];

int dfs(ii& g, int x, int& time){
	start[x] = time++;
	int total = 1;
	for (auto y : g[x]){
		if (!count[y]){
			total += dfs(g, y, time);
		}
	}
	finish[x] = time++;
	count[x] = total;
	return count[x];
}

int main(){
	int n;
	cin >> n;

	ii g(n+1);
	vector<int> top;

	for (int i = 1; i <= n; ++i){
		int u;
		cin >> u;
		if (u == 0){
			top.push_back(i);
		}
		else{
			g[u].push_back(i);
		}
	}

	int time = 0;
	for (auto x : top){
		dfs(g, x, time);
	}

	int q;
	cin>> q;
	while (q--){
		int m;
		cin >> m;
		
		vector< pair<int,bool> > nodes;
		while (m--){
			int x;
			cin  >> x;
			nodes.push_back({x, true});
		}

		for (int i = 0; i < nodes.size(); ++i){
			for (int j = i+1; j < nodes.size(); ++j){
				int x = nodes[i].first;
				int y = nodes[j].first;
				if (start[x] < start[y] and finish[y] < finish[x]){
					nodes[j].second = false;
				}
				if (start[x] > start[y] and finish[y] > finish[x]){
					nodes[i].second = false;
				}
			}
		}

		int cnt = 0;
		for (auto x : nodes){
			if (x.second)
				cnt += count[x.first];
		}
		cout << cnt << endl;

	}

	return 0;
}
