#include <iostream>
#include <vector>

#define columns 9
#define rows	5

using namespace std;

typedef pair<int,int> move;

inline bool validPos(int p){
	int r = p / rows;
	int c = p % 5;
	return r >= 0 and r < rows and c >= 0 and c < 9;
}

void get_moves(string g[], vector<move>& moves){
	moves.clear();
	for (int i = 0; i < rows; ++i){
		for (int j = 0; j < 9-3; ++j){
			if (g[i][j] == 'o' and g[i][j+1] == 'o' and g[i][j+2] == '.'){
				move m = {i*rows+j, i*rows+j+2};
				moves.push_back(m);
			}
			else if (g[i][j] == '.' and g[i][j+1] == 'o' and g[i][j+2] == 'o'){
				move m = {i*rows+j+2, i*rows+j};
				moves.push_back(m);
			}
		}
	}

	for (int i = 0; i < rows - 2; ++i){
		for (int j = 0; j < 9; ++j){
			
			if (g[i][j] == 'o' and g[i+1][j] == 'o' and g[i+2][j] == '.'){
				move m = {i*rows+j, (i+2)*rows+j};
				moves.push_back(m);
			}
			else if (g[i][j] == '.' and g[i+1][j] == 'o' and g[i+2][j] == 'o'){
				move m = {(i+2)*rows+j, i*rows+j};
				moves.push_back(m);
			}
		}
	}

}

void update(string g[], move m){
	int r1 = m.first / 
}

int main(){
	int t;
	cin >> t;

	while (t--){
		string g[rows];
		for (int i = 0; i < rows; ++i){
			cin >> g[i];
		}

	}

	return 0;
}
