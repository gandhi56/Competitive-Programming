#include <iostream>
#include <map>
#include <vector>
using namespace std;

typedef vector< vector<int> > vii;

int c, b;
int color[20];

int uncolored(){
    for (int i = 0; i < c; ++i){
        if (color[i] == 0)  return i;
    }
    return -1;
}

bool colorable(vii& g, int u, int col){
    for (auto& v : g[u]){
        if (color[v] == col)  return false;
    }
    return true;
}

bool solve(vii& g, int k){
    int u = uncolored();
    if (u == -1)    return true;

    for (int col = 1; col <= k; ++col){
        if (!colorable(g, u, col)) continue;
        color[u] = col;
        if (solve(g, k))   return true;
        color[u] = 0;
    }
    return false;
}

int main(){


	int t;
	cin >> t;

	while (t--){

		cin >> c >> b;

		for (int i = 0; i < 20; ++i){
			color[i] = 0;
		}
		
		vii g(c);
		while (b--){
			int i,j;
			cin >> i >> j;
			g[i].push_back(j);
			g[j].push_back(i);
		}

		bool planar = false;
		for (int k = 1; k <= 4; ++k){
			if (solve(g, k)){
				planar = true;
				cout << k << endl;
				break;
			}
		}

		if (!planar)	cout << "many" << endl;
	}

    return 0;
}

