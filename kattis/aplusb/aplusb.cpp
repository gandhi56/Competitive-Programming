#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	long n;
	cin >> n;

	long arr[n];
	for (long i =0 ; i < n; ++i){
		cin >> arr[i];
	}

	sort(arr, arr+n);

	long count = 0;
	for (long i = 0; i < n; ++i){
		for (long j = i+1; j < n; ++j){
			for (long k = 0; k < n; ++k){
				if (arr[i] + arr[j] == arr[k]){
					count++;
				}
			}
		}
	}

	cout << count*2 << endl;

	return 0;
}
