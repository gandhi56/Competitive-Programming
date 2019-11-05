#include <bits/stdc++.h>
using namespace std;
int main(){
	vector<bool> isprime(2000000, true);
	isprime[0] = isprime[1] = false;
	for (int p = 2; p < isprime.size(); ++p){
		if (isprime[p]){
			for (int d = 2*p; d < isprime.size(); d += p){
				isprime[d] = false;
			}
		}
	}

		
	unsigned long long tot = 0;
	for (int i = 2; i < isprime.size(); ++i){
		if (isprime[i]){
			tot += i;
		}
	}
	cout << tot << endl;

	return 0;
}
