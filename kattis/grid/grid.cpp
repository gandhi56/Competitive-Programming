#include <iostream>
#include <climits>
#include <queue>
#include <cstring>
using namespace std;

#define INF 999999

typedef pair<int,int> ii;

int n, m;
int grid[600][600];
int dist[600][600];

bool inBounds(int i, int j){
	return i >= 0 and i < n and j >= 0 and j < m;
}

void solve(int i, int j){
	for (int a = 0; a < n; ++a){
		for (int b = 0; b < m; ++b){
			dist[a][b] = -1;
		}
	}
	queue< ii > q;
	q.push({i, j});
	dist[i][j] = 0;
	while (!q.empty()){
		ii u = q.front();
		q.pop();

		i = u.first;
		j = u.second;
		int k = grid[i][j];
		if (i == n-1 and j == m-1)	break;
		for (int a : {1, -1}){
			if (inBounds(i+k*a, j) and dist[i+k*a][j] == -1){
				q.push({i+k*a, j});
				dist[i+k*a][j] = dist[i][j] + 1;
			}

			if (inBounds(i, j+k*a) and dist[i][j+k*a] == -1){
				q.push({i, j+k*a});
				dist[i][j+k*a] = dist[i][j] + 1;
			}
		}
	}

	if (dist[n-1][m-1] != -1){
		cout << dist[n-1][m-1] << endl;
	}
	else{
		cout << -1 << endl;
	}

}

void print(){
	for (int i =0 ; i < n; ++i){
		for (int j =0 ; j < m; ++j){
			cout << grid[i][j] << " ";
		}
		cout << endl;
	}
}

int main(){
	cin >> n >> m;

	for (int i = 0; i < n; ++i){
		string in;
		cin >> in;
		for (int j = 0; j < m; ++j){
			grid[i][j] =(int)(in[j] - '0');
		}
	}

	solve(0,0);
	return 0;
}
