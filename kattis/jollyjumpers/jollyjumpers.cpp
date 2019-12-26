#include <iostream>
#include <cstring>
using namespace std;

int main(){
	int n;
	while (cin >> n){
		int a[n];
		bool count[n];
		memset(count, false, sizeof(count));

		for (int i = 0; i < n; ++i){
			cin >> a[i];
		}

		for (int i = 0; i < n-1; ++i){
			count[abs(a[i]-a[i+1])] = true;
		}

		bool ok = true;
		for (int i = 1; i <= n-1; ++i){
			if (!count[i]){
				ok = false;
				break;
			}
		}

		cout << (ok? "Jolly" : "Not jolly") << endl;
	}
	return 0;
}
