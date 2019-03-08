#include <iostream>
using namespace std;

int price(int bill[], int n, int k){
	int total = 0;
	for (int i =0 ; i < n; ++i){
		if (i == k)	continue;
		total += bill[i];
	}
	return total/2;
}

int main(){
	int n, k;
	cin >> n >> k;

	int bill[n];
	for (int i = 0; i < n; ++i)	cin >> bill[i];

	int b;
	cin >> b;

	int pr = price(bill, n, k);

	if (pr == b){
		cout << "Bon Appetit" << endl;
	}
	else{
		cout << b - pr << endl;
	}

	return 0;
}
