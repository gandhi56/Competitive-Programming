
#define MAXN 20000

#include <iostream>
#include <algorithm>
using namespace std;
typedef unsigned long long ull;

ull a[MAXN];
inline bool found(int i, int j, int k){
	if (a[i] + a[j] > a[k] and a[i] + a[k] > a[j] and  a[k] + a[j] > a[i] ){
		cout << "possible" << endl;
		return true;
	}
	return false;
}

int main(){
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)	cin >> a[i];

	sort(a, a+n);

	for (int i =0 ; i < n; ++i){
		for( int j = i+1; j < n; ++j){
			int lo = j+1;
			int hi = n-1;
			while (lo <= hi){
				// invariant: a[j] >= a[i]
				int k = (lo + hi) / 2;
				if (a[k] + a[i] > a[j] and a[i] + a[j] > a[k] and a[k] + a[j] > a[i]){
					cout << "possible" << endl;
					return 0;
				}
				else if (a[k] + a[i] <= a[j]){
					lo = k + 1;
				}
				else if (a[i] + a[j] <= a[k]){
					hi = k - 1;
				}
			}

		}
	}

	cout << "impossible" << endl;
	return 0;
}
