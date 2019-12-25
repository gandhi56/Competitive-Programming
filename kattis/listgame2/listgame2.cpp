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
	for (ull d = 1; d < x; ++d){
		if (x % d == 0)
			count++;
	}

	cout << count << endl;

	return 0;
}
