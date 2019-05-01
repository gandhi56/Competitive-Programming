#include <iostream>
#include <algorithm>
using namespace std;

struct Interval{
	int s, e;
};

bool cmp(Interval a, Interval b){
	return a.e < b.e;
}

int main(){

	int n;
	cin >> n;

	Interval arr[n];
	for (int i =0 ; i < n; ++i){
		cin >> arr[i].s >> arr[i].e;
	}

	sort(arr, arr+n, cmp);

	int num = 0;
	int prev = -1;
	for (int i = 0; i < n; ++i){
		if (arr[i].s > prev){
			num++;
			prev = arr[i].e;
		}
	}

	cout << num << endl;
	return 0;
}
