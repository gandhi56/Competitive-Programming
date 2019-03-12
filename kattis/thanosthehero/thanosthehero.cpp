#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int n;
	cin >> n;

	long long a[n];
	for (int i = 0; i < n; ++i){
		cin >> a[i];
	}

	long long count = 0;
	for (int i = n - 2; i >= 0; --i){
		if (a[i] < a[i+1])	continue;
		count += a[i] - a[i+1] + 1;
		a[i] = a[i+1] - 1;
		if (a[i] < 0){
			cout << 1 << endl;
			return 0;
		}
	}

	cout << count << endl;
	
	return 0;
}
