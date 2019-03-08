#include <iostream>
using namespace std;

int main(){
	int n;
	cin >> n;

	while (n--){
		int l, n;
		cin >> l >> n;

		int minTime = -1;
		int maxTime = -1;

		for (int i =0 ; i < n; ++i){
			int p;
			cin >> p;

			int x = min(p, l-p);
			int y = max(p, l-p);

			minTime = max(minTime, x);
			maxTime = max(maxTime, y);
		}
		cout << minTime << " " << maxTime << endl;
	}

	return 0;
}
