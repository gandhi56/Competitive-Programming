// fast fourier
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

bool find(ll arr[], int n, ll x){
	int lo = 0;
	int hi = n-1;
	while (lo <= hi){
		ll mid = (lo+hi)/2;
		if (arr[mid] < x){
			lo = mid + 1;
		}
		else if (arr[mid] > x){
			hi = mid - 1;
		}
		else{
			return true;
		}
	}
	return false;
}

int main(){
	int n;
	cin>> n;

	ll nums[n];
	for (int i = 0; i < n; ++i)
		cin >> nums[i];

	int count = 0;
	sort(nums, nums+n);
	for (int i = 0; i < n; ++i){
		for (int j = i+1; j < n; ++j){
			if (find(nums, n, nums[i] + nums[j])){
				count += 2;
			}
		}
	}

	cout << count << endl;

	return 0;
}
