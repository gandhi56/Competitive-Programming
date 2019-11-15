#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;

	int a[n];
	for (int i = 0; i < n; ++i)	cin >> a[i];
	
	vector<int> ans;

	ans.push_back(a[0]);
	for (int i = 1; i < n; ++i){
		if (a[i] > ans.back()){
			ans.push_back(a[i]);
		}
	}
	cout << ans.size() << endl;
	for (auto x : ans)
		cout << x << ' ';
	cout << endl;

	return 0;
}
