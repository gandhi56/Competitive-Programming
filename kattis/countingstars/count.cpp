#include <iostream>

using namespace std;

int m, n;
char grid[101][101];
bool visited[101][101];

void dfs(int i, int j){

	visited[i][j] = true;
	int nbrs[][2] = { 	{i-1, j}, 
						{i+1, j},
						{i	, j-1},
						{i	, j+1}};

	for (int k = 0; k < 4; ++k){
		
		int ii = nbrs[k][0];
		int jj = nbrs[k][1];
		if (!visited[ii][jj] and ii >=0 and jj >= 0 and ii < m and jj < n and grid[ii][jj] == '-'){
			dfs(ii, jj);
		}
	}
}

int count(){
	int stars = 0;
	for (int i = 0; i < m; ++i){
		for (int j = 0; j < n; ++j){
			visited[i][j] = false;
		}
	}

	for (int i = 0; i < m; ++i){
		for (int j = 0; j < n; ++j){
			if (!visited[i][j] and grid[i][j] == '-'){
				dfs(i, j);
				stars++;
			}
		}
	}

	return stars;

}

int main(){

	int t = 1;
	while (cin >> m >> n){

		for (int i =0 ; i < m; ++i){
			for (int j = 0; j < n; ++j){
				cin >> grid[i][j];
			}
		}

		cout << "Case " << t << ": " << count() << endl;
		t++;

	}

	return 0;
}
