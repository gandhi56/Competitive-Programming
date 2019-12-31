#include <iostream>
#include <vector>
#include <set>
using namespace std;

typedef pair<int,int> ii;

int main(){
	int t;
	cin >> t;

	while (t--){
		int r, c;
		cin >> r >> c;

		char g[r][c];
		set<int> rows, cols;
		for (int i = 0; i < r; ++i){
			for (int j = 0; j < c; ++j){
				cin >> g[i][j];
				if (g[i][j] == '1'){
					rows.insert(i);
					cols.insert(j);
				}
			}
		}

		bool done = false;

		if (rows.size() <= 1 or cols.size() <= 1){
			for (int i =0 ; i < r; ++i){
				for (int j =0 ; j < c; ++j){
					if (g[i][j] == '1'){
						cout << 'P';
					}
					else{
						cout << 'N';
					}
				}
				cout << endl;
			}
			done = true;
		}

		if (!done){
			for (auto i : rows){
				if (done)
					break;
				for (auto j : cols){
					if (g[i][j] != '1'){
						cout << "impossible" << endl;
						done = true;
						break;
					}
					if (done)
						break;
				}
			}
		}

		if (!done){
			for (int i =0 ; i < r; ++i){
				for (int j = 0; j < c; ++j){
					if (g[i][j] == '1'){
						cout << 'I';
					}
					else{
						cout << 'N';

					}
				}
				cout << endl;
			}
		
		}

		cout << "----------" << endl;

	}

	return 0;
}
