#include <iostream>
using namespace std;

typedef unsigned long long ll;

int main(){
	ll h;
	int n;

	cin >> h >> n;

	for (int i = 0; i < n; ++i){
		int d;
		cin >> d;
		h += d;
	}



	return 0;
}
