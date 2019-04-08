#include <iostream>
#include <queue>
using namespace std;

typedef pair<int,int> ii;

int w, h;
char g[1010][1010];

void solve(ii s){
	queue<ii> q;
	q.push(s);
	while (!q.empty()){
		ii u = q.front();
		q.pop();
		for (ii k : {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}){
			ii adj = {u.first+k.first, u.second+k.second};
			if (g[u.first+k.first][u.second+k.second]=='*')
				continue;
			q.push(adj);
		}
	}
}

int main(){
	int t;
	cin >> t;

	while (t--){
		cin >> w >> h;

		ii start;
		for (int i =0 ; i < h; ++i){
			for (int j = 0; j < w; ++j){
				cin >> g[i][j];
				if (g[i][j] == '@')	start = {i, j};
			}
		}

		solve(start);
	}

	return 0;
}
