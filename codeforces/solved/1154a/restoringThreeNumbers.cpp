#include <bits/stdc++.h>
using namespace std;
int main(){
	int ar[4];
	cin >> ar[0] >> ar[1] >> ar[2] >> ar[3];

	sort(ar, ar+4);

	if (ar[3]%3 == 0 and ar[0]==2*(ar[3]/3) and ar[1]==2*(ar[3]/3) and ar[2]==2*(ar[3]/3)){
		cout << ar[3]/3 << ' ' << ar[3]/3 << ' ' << ar[3]/3 << endl;
		return 0;
	}
	
	int a, b, c;
	a = ar[3] - ar[2];
	b = ar[0] - a;
	c = ar[2] - b;
	
	cout << a << ' ' << b << ' ' << c << endl;

	return 0;
}
