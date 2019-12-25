#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

typedef vector< vector<int> > grid;

int count = 0;

void print_grid(grid& g){
	for (int i = 0; i < g.size(); ++i){
		int count = 0;
		for (auto& u : g[i]){
			cout << u;
			if (count < g.size()-1)	cout << " ";
			count++;
		}
		cout << endl;
	}
}
bool findEmptyCell(grid& g, int& row, int& col){
	for (row = 0; row < g.size(); ++row){
		for (col = 0; col < g.size(); ++col){
			if (g[row][col] == 0)	return true;
		}
	}
	return false;
}

bool isSafe(grid& g, int row, int col, int num){
	for (int i = 0; i < g.size(); ++i){
		if (g[i][col] == num)	return false;
		if (g[row][i] == num)	return false;
	}

	int startRow = row - row%((int)sqrt(g.size()));
	int startCol = col - col%((int)sqrt(g.size()));
	for (int r = 0; r*r < g.size(); ++r){
		for (int c = 0; c*c < g.size(); ++c){
			if (g[startRow+r][startCol+c] == num){
				return false;
			}
		}
	}

	return true;
}

bool check(grid& g){
	for (int i =0 ; i < 9; ++i){
		for (int j = 0; j < 9; ++j){
			if (g[i][j] == 0)	continue;
			int tmp = g[i][j];
			g[i][j] = 0;
			if (!isSafe(g, i, j, tmp)){	
				g[i][j] = tmp; 
				return false;
			}
			g[i][j] = tmp;
		}
	}
	return true;
}

bool solve(grid& g, int limit){
	int row = 0, col = 0;
	if (!findEmptyCell(g, row, col)){
		return true;
	}
	for (int num = 1; num <= g.size(); ++num){
		if (isSafe(g, row, col , num)){
			g[row][col] = num;
			if (solve(g, limit)){
				if (count > limit)	return true;
				count++;
			}
			g[row][col] = 0;
		}
	}
	return false;
}

int main(){
	int u;
	grid g(9);
	for (int i = 0; i < 9; ++i){
		for (int j = 0; j < 9; ++j){
			g[i].push_back(0);
		}
	}
	
	while (cin >> u){
		count = 0;
		g[0][0] = u;

		for (int i = 0; i < 9; ++i){
			for (int j = 0; j < 9; ++j){
				if (i == 0 and j == 0)	continue;
				cin >> u;
				g[i][j] = u;
			}
		}

		if (check(g)){
			solve(g, 1);
			if (count > 1){
				cout << "Non-unique" << endl;
			}
			else{
				solve(g, 0);
				print_grid(g);
			}
		}
		else{
			cout << "Find another job" << endl;
		}
		cout << endl;
	}

	return 0;
}
