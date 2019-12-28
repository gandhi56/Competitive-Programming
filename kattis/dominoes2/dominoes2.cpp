#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef vector< vector<int> > ii;

void dfs(ii& g, vi& a, int x){
	if (a[x] == 1)
		return;

	a[x] = 1;
	for (auto y : g[x]){
		dfs(g, a, y);
	}
}

int main(){
	int t;
	cin >> t;

	while (t--){
		int n, m, l;
		cin >> n >> m >> l;

		ii g(n+1);
		while (m--){
			int x, y;
			cin >> x >> y;
			g[x].push_back(y);
		}

		vi a(n+1, 0);
		while (l--){
			int x;
			cin >> x;
			dfs(g, a, x);
		}

		int count = 0;
		for (int i = 1; i <= n; ++i){
			count += a[i];
		}
		cout << count << endl;

	}
	return 0;
}


