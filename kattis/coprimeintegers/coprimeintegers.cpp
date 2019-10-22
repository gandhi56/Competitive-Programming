
#define MAXN 10000001

#include <iostream>
#include <vector>
using namespace std;

int main(){
	int a, b, c, d;
	cin >> a >> b >> c >> d;

	const int n = MAXN;
	int f[n];
	for (int i = 1; i < n; ++i){
		f[i] = (b/n - (a-1)/n) * (d/n - (c-1)/n);
	}

	vector<int> mu(n, -2);
	mu[1] = 1;
	for (int i = 2; i*i <= n; ++i){
		
	}

	return 0;
}
