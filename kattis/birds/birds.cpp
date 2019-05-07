#include <iostream>
#include <algorithm>
using namespace std;

int n, l, d;

int numBirds(int x, int y){
	int i = x + d;
	int a = 0;	// counter
	while (1){
		if (i >= y)	break;
		i += d;
		a++;
	}

	i = y - d;
	int b = 0;
	while (1){
		if (i <= x)	break;
		i -= d;
		b++;
	}
	return max(a, b);
}

int main(){
	cin >> l >> d >> n;

	int count = 0;
	if (n){
		int pos[n];
		for (int i = 0; i < n; ++i)	cin >> pos[i];
		sort(pos, pos+n);
		for (int i = 0; i < n-1; ++i){
			count += numBirds(pos[i], pos[i+1]);
		}
		count += numBirds(5, pos[0]);
		count += numBirds(pos[n-1], l-5);
	}
	else{
		count += numBirds(0, l-5);
	}

	cout << count << endl;
	return 0;
}
