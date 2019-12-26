#include <iostream>
using namespace std;

int main(){
	int t;
	cin >> t;

	while (t--){
		int n;
		cin >> n;
		
		int a[n];
		int k;
		for (int i =0 ; i < n; ++i)	cin >> a[i];
		for (int i = 1; i < n-1; ++i){
			if (a[i-1]+1 != a[i]){
				k = i;
				break;
			}
		}
		cout << k+1 << endl;
	}

	return 0;
}
