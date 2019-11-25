#include <iostream>
#include <algorithm>
using namespace std;

int n, l, d;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> l >> d >> n;
	int count = 0;
	if (n == 0){
		int dist = l - 12;
		count += (dist / d)	+ 1;
	}
	else{
		int pos[n];
		for (int i = 0; i < n; ++i)	cin >> pos[i];
		sort(pos, pos+n);
		int leftDist = pos[0] - 6;
		int rightDist = (l - 6) - pos[n-1];
		count += (leftDist / d) + (rightDist / d);

		for (int i = 0; i < n-1; ++i){
			count += ((pos[i+1]-pos[i]) / d) - 1;
		}
	}

	cout << count << endl;

	return 0;
}
