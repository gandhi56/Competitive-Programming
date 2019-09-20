#include <iostream>
using namespace std;

int main(){
	int p;
	cin >> p;

	while (p--){
		int k, n, d;
		char c;
		cin >> k >> n >> c >> d;
		if (d == 1){
			cout << k << " 1/" << n+1 << endl;
		}
		else{
			long depth = n / d;
			n %= d;
			d -= n;
			n += d;
			d += n*depth;
			cout << k << " " << n << "/" << d << endl;
		}
	}

	return 0;
}
