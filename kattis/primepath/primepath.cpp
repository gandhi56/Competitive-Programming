#include <iostream>
#include <bitset>
#include <cmath>
#include <queue>
#include <cstring>
using namespace std;

#define MAXN 10000

bitset<MAXN> isprime;

inline int digit(int x, int y, int i){
	return ((int)pow(10, i+1) * (x / (int)pow(10, i+1))) + 
			(((y / (int)pow(10, i)) % 10) * (int)pow(10, i)) + 
			(x % (int)pow(10, i));
}

inline int cdigit(int x, int y, int i){
	return ((int)pow(10, i+1) * (x / (int)pow(10, i+1))) + 
			(y * (int)pow(10, i)) + 
			(x % (int)pow(10, i));
}

void bfs(int x, int y){
	queue<int> q;
	int steps[10000];
	for (int i = 1000; i < 10000; ++i){
		steps[i] = -1;
	}
	steps[x] = 0;
	q.push(x);
	bool done = false;

	while (!q.empty()){
		int curr = q.front();
		q.pop();
		if (curr == y){
			done = true;
			break;
		}

		for (int i = 0; i < 4; ++i){
			for (int d = 0; d <= 9; ++d){
				if (i == 3 and d == 0)
					continue;
				int next = cdigit(curr, d, i);
				if (steps[next] != -1)
					continue;
				if (isprime[next]){
					q.push(next);
					steps[next] = steps[curr] + 1;
				}
			
			}
		}
	}
	if (!done){
		cout << "Impossible" << endl;
		return;
	}
	cout << steps[y] << endl;
}

int main(){

	// get all primes
	isprime.set();
	isprime[0] = 0;
	isprime[1] = 0;
	for (int p = 2; p*p < MAXN; ++p){
		if (isprime[p]){
			for (int d = p*p; d < MAXN; d += p){
				isprime[d] = 0;
			}
		}
	}

	int t;
	cin >> t;

	while (t--){
		int x, y;
		cin >> x >> y;
		bfs(x, y);
	}

	return 0;
}
