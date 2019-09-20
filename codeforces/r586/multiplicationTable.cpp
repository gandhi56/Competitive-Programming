#include <iostream>
#include <cmath>
using namespace std;

typedef unsigned long long ll;

ll m[1001][1001];

int main(){
	int n;
	cin >> n;

	for (int i =0 ; i < n; ++i){
		for (int j= 0; j < n; ++j){
			cin >> m[i][j];
		}
	}

	ll a[n];
	bool done;
	for (int x = 1; x <= 1000000000; ++x){
		a[0] = x;

		done = true;
		for (int i = 1; i < n; ++i){
			a[i] = m[0][i] / a[0];
			if (a[i] == 0){
				done = false;
				break;
			}
		}

		for (int i = 1; i < n; ++i){
			if (m[0][i]%a[0] != 0)
				done = false;
		}

		for (int i = 1; i < n and done; ++i){
			for (int j = i+1; j < n and done; ++j){
				if (a[i]*a[j] != m[i][j])
					done = false;
			}
		}

		if (done)
			break;
	}

	for (int i =0  ;i < n; ++i){
		cout << a[i] << " ";
	}

	return 0;
}
