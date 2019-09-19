#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int n;
	cin >> n;

	int val[n];
	for (int i= 0; i < n; ++i){
		cin >> val[i];
	}

	sort(val, val+n);

	int col = 0;
	for (int i = 0; i < n; ++i){
		bool ok = true;
		for (int j = 0; j < i; ++j){
			if (val[i]%val[j] == 0){
				ok = false;
				break;
			}
		}
		if (ok){
			col++;
		}
	}

	cout << col << endl;

	return 0;
}
