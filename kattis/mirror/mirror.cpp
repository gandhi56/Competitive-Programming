#include <iostream>
using namespace std;
int main(){
	int t;
	cin >> t;

	int k = 1;
	while (t--){
		int r, c;
		cin >> r >> c;
		char g[r][c], h[r][c];
		for (int i = 0; i < r; ++i){
			for (int j = 0; j < c; ++j){
				cin >> g[i][j];
			}
		}
		for (int i = 0; i < r; ++i){
			for (int j = 0; j < c; ++j){
				h[i][j] = g[r-i-1][c-j-1];
			}
		}

		cout << "Test " << k  << endl;
		for (int i = 0; i < r; ++i){
			for (int j = 0; j < c; ++j){
				cout << h[i][j];
			}
			cout << endl;
		}
		++k;
	}
	return 0;
}
