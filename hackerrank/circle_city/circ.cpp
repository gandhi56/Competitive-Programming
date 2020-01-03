#include <iostream>
#include <cmath>
using namespace std;

void solve(long d, long k){
	long count = 0;
	for (long i =0 ; i*i < d; ++i){
		long p = (long)sqrt((long)d - i*i);
		if (p*p + i*i == d){
			count += 4;
		}
	}

	if (count <= k){
		cout << "possible" << endl;
	}
	else{
		cout << "impossible" << endl;
	}

}

int main(){
	int t;
	cin >> t;

	while (t--){
		long d, k;
		cin >> d >> k;
		solve(d, k);
	}

	return 0;
}
