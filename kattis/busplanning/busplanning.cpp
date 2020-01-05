#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, k, c;
	cin >> n >> k >> c;

	vector<string> names;
	for (int i = 0; i < n; ++i){
		string name;
		cin >> name;
		names.push_back(name);
	}

	sort(names.begin(), names.end());

	vector< vector<bool> > bad(n, vector<bool>(n, 0));
	for (int i = 0; i < k; ++i){
		string a, b;
		cin >> a >> b;
		int u = lower_bound(names.begin(), names.end(), a) - begin(names);
		int v = lower_bound(names.begin(), names.end(), b) - begin(names);
		bad[u][v] = bad[v][u] = true;
	}

	vector<int> valid(1<<n, 0);
	for (int m = 1; m < (1<<n); ++m){
		if (__builtin_popcount(m) > c)	continue;	// 
		valid[m] = true;
		for (int i = 0; i < n; ++i){
			if ((m&(1<<i)) == 0)
				continue;
			for (int j = i+1; j < n; ++j){
				if ((m & (1<<j)) == 0){
					continue;
				}
				valid[m] &= !bad[i][j];
			}
		}
	}

	int INF = 20;
	vector<int> dp(1<<n, INF);
	dp[0] = 0;
	vector<int> jmp(1<<n, 0);
	for (int m = 1; m < (1<<n); ++m){
		for (int s = m; s; s = (s-1)&m){
			if (!valid[s])
				continue;
			if (dp[m ^ s] + 1 < dp[m]){
				dp[m] = dp[m^s] + 1;
				jmp[m] = s;
			}
		}
	}

	int cur = (1<<n) - 1;
	cout << dp[cur] << endl;
	while (cur){
		int s = jmp[cur];
		for (int i = 0; i < n; ++i){
			if (s & (1<<i)){
				cout << names[i] << " ";
			}
		}
		cout << endl;
		cur ^= s;
	}

	return 0;
}
