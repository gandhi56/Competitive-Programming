#include <bits/stdc++.h>
using namespace std;

int solve(int n){
	int cnt = 0;
	while (n){
		++cnt;
		if (n >= 100){
			n -= 100;
		}
		else if (n >= 20 and n < 100){
			n -= 20;
		}
		else if (n >= 10 and n < 20){
			n -= 10;
		}
		else if (n >= 5 and n < 10){
			n -= 5;
		}
		else{
			--n;
		}
	}
	return cnt;
}

int main(){
	int n;
	cin >> n;
	cout << solve(n) << endl;

	return 0;
}
