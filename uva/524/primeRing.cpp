#include <iostream>

using namespace std;

bool isprime[100];

bool solved(int arr[], int n){
	for (int i = 0; i < n; ++i){
		if ( !isprime[arr[i] + arr[(i+1)%n]] )
			return false;
	}
	return true;
}

bool solve(int arr[], int i, int n){
	if (i >= n){
		return true;
	}

	for (int num = 2; num <= n; ++num){
		arr[i] = num;
		for (int num2 = )
		if (solve(arr, i+1, n))
			return true;
		arr[i] = -1;
	}
	return false;
}

int main(){
	// sieve
	for (int i = 0; i < 100; ++i)	isprime[i] = true;
	isprime[0] = false;
	isprime[1] = false;
	for (int p = 2; p < 100; ++p){
		int k = p*2;
		while (k < 100){
			isprime[k] = false;
			k += p;
		}
	}

	int n;
	cin >> n;

	int arr[n];
	for (int i = 0; i < n; ++i)	arr[i] = -1;
	arr[0] = 1;
	return 0;
}
