#include <bits/stdc++.h>
using namespace std;

vector<int> prisonAfterNDays(vector<int>& cells, int N) {
	char x = 0;
	for (int i = 0; i < 8; ++i){
		x |= cells[i]<<i;
	}

	while (N--){
		int tmp;
		for (int i =0 ; i < 8; ++i){
			if (i == 0){
				tmp = x&(1<<7);
				x ^= (1<<7);
			}
			else if (x&(i+1) == tmp){
				
			}
		}
	}

	return cells;
}

int main(){
	vector<int> cells = vector<int>({0,1,0,1,1,0,0,1});
	int n = 7;
	vector<int> ans = prisonAfterNDays(cells, n);
	// for (auto x : ans)
	// 	cout << x << ' ';
	// cout << endl;
	return 0;
}