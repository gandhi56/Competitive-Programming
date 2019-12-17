#include <iostream>
#include <queue>
#include <vector>
using namespace std;


typedef pair<int,int> ii;

int n;

bool inBounds(ii p){
	return p.first >= 1 and p.first <= n and p.second >= 1 and p.second <= n;
}

int main(){
	cin >> n;

	ii start;
	char g[n+1][n+1];
	int d[n+1][n+1];
	for (int i = 1; i <= n; ++i){
		for (int j = 1; j <= n; ++j){
			cin >> g[i][j];
			d[i][j] = 1e6;
			if (g[i][j] == 'K'){
				start = {i, j};
				d[i][j] = 0;
			}
		}
	}

	queue< ii > q;
	ii curr;
	q.push(start);
	while (!q.empty()){
		curr = q.front();
		q.pop();

		if (curr.first == 1 and curr.second == 1){
			break;
		}


		vector<ii> adjPos;
		adjPos.push_back({curr.first+2, curr.second+1});
		adjPos.push_back({curr.first+2, curr.second-1});
		adjPos.push_back({curr.first-2, curr.second+1});
		adjPos.push_back({curr.first-2, curr.second-1});
		adjPos.push_back({curr.first+1, curr.second+2});
		adjPos.push_back({curr.first+1, curr.second-2});
		adjPos.push_back({curr.first-1, curr.second+2});
		adjPos.push_back({curr.first-1, curr.second-2});
		
		for (ii adj : adjPos){
			if (inBounds(adj) and g[adj.first][adj.second] == '.'){
				g[adj.first][adj.second] = '#';
				q.push(adj);
				d[adj.first][adj.second] = d[curr.first][curr.second] + 1;
			}
		}

	}

	cout << (d[1][1]==1e6?-1:d[1][1]) << endl;

	return 0;
}

