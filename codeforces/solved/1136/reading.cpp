#include <iostream>
using namespace std;

int main(){
	int n;
	cin >> n;

	int f[n];
	int s[n];
	for (int i =0 ; i < n; ++i){
		cin >> f[i] >> s[i];
	}

	int k;
	cin >> k;

	int count = n;
	for (int i = 0; i < n; ++i){
		if (k > s[i])	count--;
	}

	cout << count << endl;

	return 0;
}
