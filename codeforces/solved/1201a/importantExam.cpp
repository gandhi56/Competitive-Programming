#include <bits/stdc++.h>
using namespace std;
int main(){
	int n, m;
	cin >> n >> m;

	char ans[n][m];
	for (int i = 0; i < n; ++i){
		scanf("%s", ans[i]);
	}

	int a[m];
	for (int i = 0; i < m; ++i)	cin >> a[i];

	int pts = 0;
	for (int i = 0; i < m; ++i){
		// question i, find the best answer
		unordered_map<char, int> count;
		for (int j = 0; j < n; ++j){
			count[ans[j][i]]++;
		}

		pair<char, int> best = {'0', 0};
		for (auto it : count){
			if (it.second > best.second){
				best = it;
			}
		}

		//cout << "best = " << best.first << ' ' << best.second << endl;

		// found correct answer

		int p = 0;
		for (int j = 0; j < n; ++j){
			if (ans[j][i] == best.first){
				p += a[i];
			}
		}
		//cout << "points earned = " << p << endl;
		pts += p;
	}
	cout << pts << endl;


	return 0;
}
