#include <iostream>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int x;
	cin >> x;

	int count = 0;
	for (int d = 2; d*d<=x; ++d){
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
