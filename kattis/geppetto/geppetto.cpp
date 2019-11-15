#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

bool ok[22][22];

int main(){
	memset(ok, true, sizeof(ok));
	int n, m;
	cin >> n >> m;
	while (m--){
		int i, j;
		cin >> i >> j;
		ok[--i][--j] = false;
		ok[j][i] = false;
	}

	int cnt = 0;
	for (int i = 0; i < (1<<n); ++i){
		bool good = true;
		for (int j = 0; j < n and good; ++j){
			for (int k = j+1; k < n and good; ++k){
				if (i&(1<<j) and i&(1<<k) and !ok[j][k]){
					good = false;
				}
			}
		}
		if (good)	++cnt;
	}
	cout << cnt << endl;

	return 0;
}
