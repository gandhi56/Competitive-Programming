#include <iostream>
using namespace std;

int sort(int arr[], int n){
	int count = 0;

	for (int i = 1; i < n; ++i){
		int tmp = arr[i];
		int j = 0;
		while (j < i and arr[j] <= arr[i])	++j;

		for (int k = i; k > j; --k){
			arr[k] = arr[k-1];
			count++;
		}
		arr[j] = tmp;
	}

	return count;
}

int main(){
	int p;
	cin >> p;

	while (p--){
		int k;
		cin >> k;

		int arr[30];
		for (int i = 0; i < 20; ++i){
			cin >> arr[i];
		}

		cout << k << " " << sort(arr, 20) << endl;
	}

	return 0;
}
