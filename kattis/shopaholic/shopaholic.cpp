#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(int a, int b){
	return a > b;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	int a[n];
	for (int i = 0; i < n; ++i){
		cin >> a[i];
	}

	sort(a, a+n, cmp);

	unsigned long long d = 0;
	for (int i = 0; i < n; ++i){
		if (i%3 == 2)
			d += a[i];
	}
	cout << d << endl;

	return 0;
}
