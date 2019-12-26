#include <iostream>
using namespace std;

int main(){
	int n;
	cin >> n;

	int y = 2018, m = 3;
	while (y < n){
		m += 26;
		while (m >= 12){
			m -= 12;
			y += 1;
		}
	}

	if (y == n){
		cout << "yes" << endl;
	}
	else{
		cout << "no" << endl;
	}

	return 0;
}
