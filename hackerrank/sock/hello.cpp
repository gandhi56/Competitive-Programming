#include <iostream>
#include <map>
using namespace std;

int main(){
	int n;
	cin >> n;

	map<int,int> count;
	for (int i = 1; i <= 100; ++i){
		count[i] = 0;
	}

	for (int i = 0; i < n; ++i){
		int val;
		cin >> val;
		count[val]++;
	}

	int total = 0;

	for (int i = 1; i <= 100; ++i){
		total += count[i]/2;
	}
	cout << total << endl;

	return 0;
}
