#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i){
		if (i == n-1){
			cout << (i&1? "I love it":"I hate it");
		}
		else{
			cout << (i&1? "I love that ":"I hate that ");
		}
	}
	cout <<endl;
	return 0;
}
