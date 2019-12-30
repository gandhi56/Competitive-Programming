#include <iostream>
using namespace std;

double p[101];


int main(){
	int n;
	cin >> n;

	int x;
	for (int i = 0; i < n; ++i){
		cin >> x;
		p[i] = (double)(x / 100);
	}

	return 0;
}
