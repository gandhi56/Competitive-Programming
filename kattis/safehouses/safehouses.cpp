#include <iostream>
#include <vector>
using namespace std;

typedef pair<int,int> ii;

char g[200][200];

int main(){
	int n;
	cin >> n;

	vector<ii> spies;
	vector<ii> houses;
	for (int i = 0; i < n; ++i){
		for (int j =0 ; j < n; ++j){
			cin >> g[i][j];
			if (g[i][j] == 'S')	spies.push_back({i,j});
			if (g[i][j] == 'H')	houses.push_back({i,j});
		}
	}

	int ans = 0;
	for (auto spy : spies){
		int best = 9999;
		for (auto house : houses){
			best = min(best, abs(spy.first - house.first) + abs(spy.second-house.second));
		}
		ans = max(ans, best);
	}

	cout << ans << endl;

	return 0;
}
