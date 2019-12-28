#include <iostream>

using namespace std;

int main(){
	int n;
	while (cin >> n){
		int ans = 1%n, digits = 1;
		while (ans){
			ans = (10*ans + 1) % n;
			digits++;
		}
		cout << digits << endl;
	}
	return 0;
}
