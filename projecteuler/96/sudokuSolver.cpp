#define N 9

#include <bits/stdc++.h>
using namespace std;

char grid[N][N];

void show(){
	cout << endl;
	for (int i = 0; i < N; ++i){
		for (int j = 0; j < N; ++j){
			cout << grid[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

bool checkrow(int row, char val){
	for (int col = 0; col < N; ++col){
		if (grid[row][col] == val){
			return true;
		}
	}
	return false;
}

bool checkcol(int col, char val){
	for (int row = 0; row < N; ++row){
		if (grid[row][col] == val){
			return true;
		}
	}
	return false;
}

bool checkminor(int startRow, int startCol, char val){
	for (int row = 0; row < 3; ++row){
		for (int col = 0; col < 3; ++col){
			if (grid[startRow+row][startCol+col] == val)	return true;
		}
	}
	return false;
}

bool findIdx(int& row, int& col){
	for (row = 0; row < N; ++row){
		for (col = 0; col < N; ++col){
			if (grid[row][col] == '0')	return true;
		}
	}
	return false;
}

bool isvalid(int row, int col, char val){
	return !checkrow(row, val) and 
			!checkcol(col, val) and 
			!checkminor(row - row%3, col - col%3, val) and 
			grid[row][col] == '0';
}

bool solve(){
	int row, col;
	if (!findIdx(row, col)){
		return true;
	}
	#ifdef debug
		cout << "unassigned " << row << " " << col << endl;
	#endif

	for (char val = '1'; val <= '9'; ++val){
		if (isvalid(row, col, val)){
			grid[row][col] = val;

			#ifdef debug
				cout << "assigning " << row << ' ' << col << endl;
			#endif

			if (solve()){
				return true;
			}
			grid[row][col] = '0';
		}
	}

	return false;
}

int main(){
	int tot =0 ;
	while (1){
		string s;
		int num;
		cin >> s >> num;
	
		// read puzzle
		for (int i = 0; i < N; ++i){
			scanf("%s", grid[i]);
		}

		solve();
		//show();


		int n = (grid[0][0] - '0')*100 + (grid[0][1] - '0')*10 + (grid[0][2] - '0');
		tot += n;
		if (num == 50)	break;

	}
	cout << tot << endl;

	return 0;
}
