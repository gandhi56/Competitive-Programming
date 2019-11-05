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

	cout << "done" << endl;

	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;

		if (n == 1){
			cout << 0 << endl;
			continue;
		}

		int count =0;
		for (int x = 1; x < n; ++x){
			for (int y = 1; x*x + y*y*y*y <= n; ++y){
				if (isprime[x*x + y*y*y*y]){
					count++;
				}
			}
		}
		cout << count << endl;
	}

	return 0;
}
