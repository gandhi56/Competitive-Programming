#include <iostream>
#include <bitset>
#include <vector>
using namespace std;

#define MAXN 1000000

bitset<MAXN> isprime;

int count;

void f(int n){
	int x = 0;
	for (int p = 2; p*p <= n; ++p){
		while (n%p == 0){
			n /= p;
			x += p;
		}
	}
	count++;
	if (x == 0){
		cout << n << " " << count << endl;
		return;
	}
	if (n != 1)	x += n;
	f(x);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	while (cin >> n){
		if (n == 4)	break;
		count = 0;
		f(n);
	}

	return 0;
}
