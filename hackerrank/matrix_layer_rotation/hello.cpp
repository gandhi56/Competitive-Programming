#include <iostream>

using namespace std;

int a[302][302];

int get_row2(int m, int n, int row){
	return m - row - 1;
}

int get_col2(int m, int n, int col){
	return n - col - 1;
}

void rotate_layer(int row, int col, int r){
		
}

int main(){
	int m, n, r;
	cin >> m >> n >> r;

	for (int i = 0; i < m; ++i){
		for (int j = 0; j < n; ++j){
			cin >> a[i][j];
		}
	}



	return 0;
}
