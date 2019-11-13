#include <bits/stdc++.h>
using namespace std;
int main(){
	int q;
	cin >> q;
	while (q--){
		int n;
		cin >> n;

		int a[n];
		for (int i = 0; i < n; ++i)	cin >> a[i];

		bool op[n];
		memset(op, false, sizeof(op));

		for (int x = 1; x <= n; ++x){
			// find the smallest element
			int idx = 0;
			for (idx = 0; idx+1 < n; ++idx){
				if (a[idx+1] == x){
					break;
				}
			}

			// x is the first element, nothing can be done
			if (idx == 0)	continue;

			// perform consecutive swaps to push x to the left
			// invariant : a[idx+1] = x
			while (idx >= 0 and idx+1 < n){
				if (!op[idx] and x < a[idx]){
					swap(a[idx], a[idx+1]);
					op[idx] = true;
					--idx;	// x is at idx now
				}
				else{
					break;
				}
			}
		}

		for (int i = 0; i < n; ++i){
			cout << a[i] << ' ';
		}
		cout << endl;

	}
	return 0;
}
