#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

int main(){
	int n;
	cin >> n;

	int arr[n];
	for (int i = 0; i < n; ++i)	cin >> arr[i];

	sort(arr, arr + n, greater<int>());

	int i = 0;
	int pay = 0;
	while (i+2 < n){
		pay += arr[i] + arr[i+1];
		i += 3;
	}

	while (i < n){
		pay += arr[i];
		i++;
	}
	cout << pay << endl;
	return 0;
}
