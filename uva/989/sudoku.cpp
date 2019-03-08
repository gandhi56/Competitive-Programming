#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

typedef vector< vector<int> > grid;


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

bool solve(grid& g){
	int row = 0, col = 0;
	if (!findEmptyCell(g, row, col))	return true;
	for (int num = 1; num <= g.size(); ++num){
		if (isSafe(g, row, col , num)){
			g[row][col] = num;
			if (solve(g)){
				return true;
			}
			g[row][col] = 0;
		}
	}

}

int main(){
	int n;
	while (cin >> n){
		grid g(n*n);
		for (int i = 0; i < n*n; ++i){
			for (int j = 0; j < n*n; ++j){
				int u;
				cin >> u;
				g[i].push_back(u);
			}
		}
		if (solve(g)){
			print_grid(g);
		}
		else{
			cout << "NO SOLUTION" << endl;
		}
		cout << endl;
	}

	return 0;
}
