#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

int main(){
	int n;
	cin >> n;

	int times[n];
	for (int i =0 ; i < n; ++i)	cin >> times[i];

	sort(time, times+n, greater<int>());



	return 0;
}
