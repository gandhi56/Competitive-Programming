#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;

	map<int,int> a;
	a[-1] = 1;
	for (int i = 1; i <= n-1; ++i){
		int x;
		cin>> x;
		a.insert({x, i+1});
	}

	for (auto x : a)
		cout << x.second << ' ';
	cout << endl;

	return 0;
}
