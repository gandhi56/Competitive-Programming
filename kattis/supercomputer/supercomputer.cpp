#include <iostream>
#include <cstring>
using namespace std;

bool bits[1000000];
long arr[1000000];
int n, k;

long sum(int i){
	long s = 0;
	while (i){
		s += arr[i];
		i -= i & -i;
	}
	return s;
}

long interval_sum(int i, int j){
	return sum(j) - sum(i);
}

void add(int i, int k){
	while (i <= n){
		arr[i] += k;
		i += i & -i;
	}
}

int main(){
	cin >> n >> k;

	memset(bits, false, sizeof(bits));
	memset(arr, 0, sizeof(arr));

	while (k--){
		char c;
		cin >> c;
		if (c == 'F'){
			int i;
			cin >> i;
			if (bits[i]){
				add(i, -1L);
			}
			else{
				add(i, 1L);
			}
			bits[i] ^= 1;
		}
		else if (c == 'C'){
			int l, r;
			cin >> l >> r;
			cout << interval_sum(l-1, r) << endl;
		}
	}
	return 0;
}
