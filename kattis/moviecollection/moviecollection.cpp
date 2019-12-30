#include <iostream>
#include <cstring>
using namespace std;

#define MAXN 100005

int n, r;
int bit[2*MAXN];
int pos[MAXN];

void update(int idx, int delta){
	for (int i = idx; i < 2*MAXN; i += (i & -i)){
		bit[i] += delta;
	}
}

int sum(int idx){
	int sum = 0;
	for (int i = idx; i > 0; i -= (i & -i)){
		sum += bit[i];
	}
	return sum;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	while (t--){
		memset(bit, 0, sizeof(bit));
		cin >> n >> r;

		for (int i = 1; i <= n; ++i){
			update(i, 1);
			pos[i] = n - i + 1;
		}

		for (int i = n+1; i <= n+r; ++i){
			int id;
			cin >> id;
			cout << n-sum(pos[id]) << " ";
			update(pos[id], -1);
			update(i, 1);
			pos[id] = i;
		}
		cout << endl;
	}

	return 0;
}
