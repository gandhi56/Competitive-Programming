#include <bits/stdc++.h>
using namespace std;
int main(){
	int a, b, m, sig;
	cin >> a >> b >> m >> sig;
	int x = 1;
	int y = m-1;

	if (a > b){
		x = m-1;
		y = 1;
	}
	while (2*x + y < sig){
		if (a <= b){
			x++; y--;
		}
		else{
			x--; y++;
		}
	}
	cout << a*x + b*y << endl;

	return 0;
}
