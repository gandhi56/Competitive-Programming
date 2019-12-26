#include <bits/stdc++.h>
using namespace std;
int main(){
	int idx = 1;
	for (int p = 2; idx <= 10001; ++p){
		bool isprime = true;
		for (int d = 2; d*d <= p; ++d){
			if (p%d == 0){
				isprime = false;
				break;
			}
		}
		if (isprime){
			cout << idx++ << ' ' << p << endl;
		}
	}
	return 0;
}
