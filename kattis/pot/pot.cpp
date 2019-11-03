#include <iostream>
#include <cmath>
using namespace std;

int main(){
	int n;
	cin >> n;

	int tot = 0;
	for (int i = 0; i < n; ++i){
		int x;
		cin >> x;
		int p = x%10;
		x /= 10;
		tot += pow(x, p);
	}
	cout << tot << endl;
	return 0;
}
