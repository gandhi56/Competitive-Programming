#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;

int main(){
	int n;
	cin >> n;

	ll sour[n];
	ll bitter[n];
	for (int i = 0; i < n; ++i){
		cin >> sour[i] >> bitter[i];
	}

	ll minDiff = 1e9;
	for (int i = 1; i < pow(2, n); ++i){
		ll s = 1, b = 0;
	
		for (int j = 0; j < n; ++j){
			if (i & (1 << j)){
				s *= sour[j];
				b += bitter[j];
			}
		}

		minDiff = min(minDiff, abs(s - b));
	
	}

	cout << minDiff << endl;

	return 0;
}
