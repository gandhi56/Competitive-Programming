#include <iostream>
#include <vector>
using namespace std;

bool ok[22][22];

int main(){
	for (int i =0 ; i < 22; ++i){
		for (int j =0; j < 22; ++j){
			ok[i][j] = true;
		}
	}

	int n, m;
	cin >> n >> m;

	while (m--){
		int i, j;
		cin >> i >> j;
		ok[i][j] = false;
		ok[j][i] = false;
	}

	for (int i = 0; i < (1<<n); ++i){
		vector<int> sub;
		for (int j = 0)
	}

	return 0;
}
