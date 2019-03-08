#include <iostream>
using namespace std;

int ceilIndex(int arr[], int lo, int hi, int key){
	while (hi - lo > 1){
		int mid = lo + (hi - lo)/2;
		if (arr[mid] >= key){
			hi = mid;
		}
		else{
			lo = mid;
		}
	}

	return hi;
}

void lis(int arr[], int n){
	if (n == 0)	return;
	int tail[n] = {0};
	int len = 1;

	tail[0] = arr[0];
	for (int i = 1; i < n; ++i){
		if (arr[i] < tail[0]){
			tail[0] = arr[i];
		}
		else if (arr[i] > tail[len-1]){
			tail[len++] = arr[i];
		}
		else{
			tail[ceilIndex(tail, -1, len-1, arr[i])] = arr[i];
		}
	}

	cout << len << endl;
}

int main(){
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; ++i)	cin >> arr[i];
	lis(arr, n);

	return 0;
}
