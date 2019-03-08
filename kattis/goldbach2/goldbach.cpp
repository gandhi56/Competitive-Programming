#include <iostream>
#include <bitset>
#include <vector>
#define N 40000

using namespace std;

int main(){

	bitset<N> isprime;
	isprime.set();

	isprime[0] = 0;
	isprime[1] = 0;

	for (int p = 2; p*p < N; ++p){
		if (isprime[p]){
			for (int i = p*p; i < N; i += p){
				isprime.set(i, false);
			}
		}
	}

	int n;
	cin >> n;

	while (n--){
		int x;
		cin >> x;

		vector< pair<int,int> > reps;

		for (int u = 2; u <= x/2; ++u){
			if (isprime[u] and isprime[x-u]){
				reps.push_back({u, x-u});
			}
		}

		cout << x << " has " << reps.size() << " representation(s)";
		cout << endl;
		for (pair<int,int> p : reps){
			cout << p.first << "+" << p.second << endl;
		}
		cout << endl;

	}
	return 0;
}
