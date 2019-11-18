
#define N 4
#include <bits/stdc++.h>
using namespace std;
int grid[N][N];

void slide_left(){
	for (int row = 0; row < N; ++row){
		int collided = -1;
		int col;
		int blankIdx = 0;
		for (col = 0; col < N; ++col){
			if (grid[row][col] == 0)	continue;
			
			if (blankIdx == 0){
				swap(grid[row][blankIdx], grid[row][col]);
				++blankIdx;
			}
			else{
				if (grid[row][blankIdx-1] == grid[row][col] and collided < blankIdx-1){
					// double value!
					grid[row][blankIdx-1] <<= 1;
					grid[row][col] = 0;
					collided = blankIdx-1;
				}
				else{
					swap(grid[row][blankIdx], grid[row][col]);
					++blankIdx;
				}
			}
		}
	}
}

void slide_right(){
	for (int row = 0; row < N; ++row){
		int collided = N;
		int col;
		int blankIdx = N-1;
		for (col = N-1; col >= 0; --col){
			if (grid[row][col] == 0)	continue;
			
			if (blankIdx == N-1){
				swap(grid[row][blankIdx], grid[row][col]);
				--blankIdx;
			}
			else{
				if (grid[row][blankIdx+1] == grid[row][col] and collided > blankIdx+1){
					// double value!
					grid[row][blankIdx+1] <<= 1;
					grid[row][col] = 0;
					collided = blankIdx+1;
				}
				else{
					swap(grid[row][blankIdx], grid[row][col]);
					--blankIdx;
				}
			}
		}
	}
}

void slide_up(){
	for (int col = 0; col < N; ++col){
		int collided = -1;
		int row;
		int blankIdx = 0;
		for (row = 0; row < N; ++row){
			if (grid[row][col] == 0)	continue;
			
			if (blankIdx == 0){
				swap(grid[blankIdx][col], grid[row][col]);
				++blankIdx;
			}
			else{
				if (grid[blankIdx-1][col] == grid[row][col] and collided < blankIdx-1){
					// double value!
					grid[blankIdx-1][col] <<= 1;
					grid[row][col] = 0;
					collided = blankIdx-1;
				}
				else{
					swap(grid[blankIdx][col], grid[row][col]);
					++blankIdx;
				}
			}
		}
	}

}


void slide_down(){
	for (int col = 0; col < N; ++col){
		int collided = N;
		int row;
		int blankIdx = N-1;
		for (row = N-1; row >= 0; --row){
			if (grid[row][col] == 0)	continue;
			
			if (blankIdx == N-1){
				swap(grid[blankIdx][col], grid[row][col]);
				--blankIdx;
			}
			else{
				if (grid[blankIdx+1][col] == grid[row][col] and collided > blankIdx+1){
					// double value!
					grid[blankIdx+1][col] <<= 1;
					grid[row][col] = 0;
					collided = blankIdx+1;
				}
				else{
					swap(grid[blankIdx][col], grid[row][col]);
					--blankIdx;
				}
			}
		}
	}
}

void show_grid(){
	for (int i = 0; i < 4; ++i){
		for (int j = 0; j < 4; ++j){
			cout << grid[i][j] << ' ';
		}
		cout << endl;
	}
}


int main(){
	for (int i = 0; i < 4; ++i){
		for (int j = 0; j < 4; ++j){
			cin >> grid[i][j];
		}
	}

	int a;
	cin >> a;

	if (a == 0)			slide_left();
	else if (a == 1)	slide_up();
	else if (a == 2)	slide_right();
	else if (a == 3)	slide_down();

	show_grid();



	return 0;
}
