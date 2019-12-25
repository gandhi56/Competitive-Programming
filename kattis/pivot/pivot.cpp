#include <iostream>
using namespace std;

int main(){
	int n;
	cin >> n;

	int a[n];
	for (int i =0 ; i < n; ++i){
		cin >> a[i];
	}

	int left[n];
	int maxsofar = a[0];
	left[0] = a[0];
	for (int i =1 ; i < n; ++i){
		maxsofar = max(maxsofar, a[i]);
		left[i] = maxsofar;
	}

	int right[n];
	int minsofar = a[n-1];
	for (int i = n-1; i >= 0; --i){
		minsofar = min(minsofar, a[i]);
		right[i] = minsofar;
	}

	int count = 0;
	for (int i = 0; i < n; ++i){
		if (left[i] <= a[i] and a[i] <= right[i])
			count++;
	}
	cout << count << endl;

	return 0;
}
