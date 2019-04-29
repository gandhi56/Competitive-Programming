#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAXN 2001

int cap, n;
int v[MAXN];
int w[MAXN];

void solve(){
	int dp[n+1][cap+1];
	for (int i = 0; i <= n; ++i){
		for (int j = 0; j <= cap; ++j){
			if (i == 0 or j == 0){
				dp[i][j] = 0;
			}
			else if (w[i-1] <= j){
				dp[i][j] = max(v[i-1] + dp[i-1][j-w[i-1]], dp[i-1][j]);
			}
			else{
				dp[i][j] = dp[i-1][j];
			}
		}
	}

	int j = cap;
	int res = dp[n][cap];
	vector<int> items;
	for (int i = n; i and res; --i){
		if (res == dp[i-1][j])	continue;
		items.push_back(i-1);
		res = res - v[i-1];
		j = j - w[i-1];
	}
	cout << items.size() << endl;
	reverse(items.begin(), items.end());
	for (int item : items){
		cout << item << " ";
	}
	cout << endl;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	while (cin >> cap >> n){
		for (int i = 0; i <  n; ++i){
			cin >> v[i] >> w[i];
		}

		solve();

	}

	return 0;
}
