#include <iostream>
#include <climits>
using namespace std;

int g[101][101];
int rsum[101];
int csum[101];
int x, y;

int get_cost(int xx, int yy){
	int cost = 0;
	for (int i = 0; i < y; ++i){
		for (int j = 0; j < x; ++j){
			cost += (abs(xx - j) + abs(yy - i)) * g[i][j];
		}
	}
	return cost;
}

int main(){
	int t;
	cin >> t;

	while (t--){
		cin >> x >> y;

		for (int i = 0; i < y; ++i){
			for (int j =0 ; j < x; ++j){
				cin >> g[i][j];
			}
		}
		
		for (int r = 0; r < y; ++r){
			int total =0 ;
			for (int c =0 ; c < x; ++c){
				total += g[r][c];
			}
			if (total){
				rsum[r] = rsum[r-1] + total;
			}
			else{
				rsum[r] = total;
			}
		}

		for (int c = 0; c < x; ++c){
			int total =0 ;
			for (int r =0 ; r < y; ++r){
				total += g[r][c];
			}
			if (total){
				csum[c] = csum[c-1] + total;
			}
			else{
				csum[c] = total;
			}
		}
		
		int minCost = get_cost(0, 0);
		for (int yy = 0; yy < y; ++yy){
			for (int xx = 0; xx < x; ++xx){
				//minCost = min(minCost, cost(yy, xx));
			}
		}

		cout << minCost << " blocks" << endl;

	}

	return 0;
}
