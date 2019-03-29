#include <iostream>
#include <algorithm> 
using namespace std;

void solve(int h[], int n){
	sort(h, h+n);
	int c = 0, loc = 0;
	int i;
	for (i = 0; i < n; ++i){
		if (h[i]+loc > n+c)	break;
		if (h[i] > c)	c++;
	}
	c += n-i;
	cout << c << endl;
}

int main(){
	int n;
	cin >> n;
	
	int h[n];
	for (int i = 0; i < n; ++i)	cin >> h[i];

	solve(h, n);

	return 0;
}
