#include <iostream>
#include <cstring>
using namespace std;

int main(){
	int n, t;
	cin >> n >> t;

	int ok[t+2];
	memset(ok, 0, sizeof(ok));

	for (int i = 0; i < n; ++i){
		int m, k;
		cin >> m >> k;

		for (int j = k; j >= 0; --j){
			if (m > ok[j])	swap(m, ok[j]);
		}
	}

	int total = 0;
	for (int i = 0; i < t; ++i){
		total += ok[i];
	}
	cout << total << endl;

	return 0;
}
