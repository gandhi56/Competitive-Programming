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

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	while (t--){
		cin >> x >> y;

		for (int i = 0; i < y; ++i){
			for (int j =0 ; j < x; ++j){
				cin >> g[i][j];
			}
		}
		
		
		int minCost = get_cost(0, 0);
		for (int yy = 0; yy < y; ++yy){
			for (int xx = 0; xx < x; ++xx){

				int cost = 0;
				for (int i = 0; i < y; ++i){
					for (int j = 0; j < x; ++j){
						cost += (abs(xx - j) + abs(yy - i)) * g[i][j];
						if (cost > minCost){
							goto done;
						}
					}
				}
		done:
				minCost = min(minCost, cost);

			}
		}

		cout << minCost << " blocks" << endl;

	}

	return 0;
}
