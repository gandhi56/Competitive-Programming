#include <iostream>
#include <algorithm>
using namespace std;

int flipSort(int* arr, int n){
	int swaps = 0;
	for (int i = 0; i < n; ++i){
		for (int j = n-2; j >= 0; --j){
			if (arr[j] > arr[j+1]){	
				swaps++;
				swap(arr[j], arr[j+1]);
			}
		}
	}

	return swaps;
}

int main(){
	int n;

	while (cin >> n){
		int arr[n];
		for (int i = 0; i < n; ++i)	cin >> arr[i];
		cout << "Minimum exchange operations : " << flipSort(arr, n) << endl;
	}

	return 0;
}
