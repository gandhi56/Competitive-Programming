#include <iostream>
#include <map>
using namespace std;

int main(){
	int n;
	cin >> n;

	map<int,int> count;
	for (int i = 1; i < 100; ++i){
		count[i] = 0;
	}

	for (int i = 0 ; i < n; ++i){
		int val;
		cin >> val;
		count[val]++;
	}

	int maxSum = 0;
	for (int i = 1; i < 99; ++i){
		maxSum = max(maxSum, count[i]+count[i+1]);
	}

	cout << maxSum << endl;

	return 0;
}
