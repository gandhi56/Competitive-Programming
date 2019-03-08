#include <iostream>
#include <climits>
using namespace std;

#define INF 999999

int n, m;
int grid[600][600];
int dp[600][600];
bool visited[600][600];

bool inBounds(int i, int j){
	return i >= 0 and i < n and j >= 0 and j < m;
}

int solve(int i, int j){
	cout << i << " " << j << endl;
	if (visited[i][j]){
		return INF;
	}
	visited[i][j] = true;
	if (i == n-1 and j == n-1){
		return 0;
	}
	else{
		int step = grid[i][j];
		int count = INF;
		if (inBounds(i+step, j)){
			count = min(count, 1+solve(i+step, j));
		}
		if (inBounds(i-step, j)){
			count = min(count, 1+solve(i-step, j));
		}
		if (inBounds(i, j+step)){
			count = min(count, 1+solve(i, j+step));
		}
		if (inBounds(i, j-step)){
			count = min(count, 1+solve(i, j-step));
		}
		return count;
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
			dp[i][j] = -1;
			visited[i][j] = false;
		}
	}
	cout << solve(0,0) << endl;

	return 0;
}
