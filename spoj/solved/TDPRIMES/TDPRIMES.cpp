#define MAXN 100000000
#include <bits/stdc++.h>
using namespace std;
int main(){
	int maxn = 1e8;
	vector<bool> isprime(maxn + 1, true);
	isprime[0] = isprime[1] = false;
	for (int p = 2; p <= maxn; ++p){
		//cout << p << endl;
		if (isprime[p] and (long long)p*p <= maxn){
			for (int d = p*p; d <= maxn; d += p){
				//cout << d << endl;
				isprime[d] = false;
			}
		}
	}

	int idx = 1;
	for (int i = 2; i <= maxn; ++i){
		if (isprime[i])	{
			if (idx%100 == 1){
				cout << i << endl;
			}
			idx++;
		}
	}

	return 0;
}
