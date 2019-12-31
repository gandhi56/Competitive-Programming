#include <iostream>
using namespace std;

typedef unsigned long long ull;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ull x;
	cin >> x;

	ull count = 0;
	for (ull d = 2; d*d<=x; ++d){
		while (x%d == 0){
			x /= d;
			count++;
		}
	}

	if (x > 1){
		count++;
	}

	cout << count << endl;

	return 0;
}
