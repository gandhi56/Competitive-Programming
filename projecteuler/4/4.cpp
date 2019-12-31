#include <bits/stdc++.h>
using namespace std;

int digit(int n, int i){
	return (n / (int)pow(10, i)) % 10;
}

bool ispal(int num){
	int h = 6;
	if (num >= 10000 and num <= 99999)	h = 5;
	if (num >= 1000 and num <= 9999)	h = 4;
	cout << num << " ";
	for (int i = 0; i < h; ++i)	cout << digit(num, i) << ' ';
	cout << endl;
	return digit(num, 0) == digit(num, h-1) and 
			digit(num, 1) == digit(num, h-2) and
			digit(num, 2) == digit(num, h-3);
}

int main(){
	bool done = false;
	int maxPal = 0;
	for (int a = 999; a >= 100 and !done; --a){
		for (int b = 999; b >= 100 and !done; --b){
			if (ispal(a*b)){
				cout << a << " x " << b << " = " << a*b << endl;
				maxPal = max(maxPal, a*b);
			}
		}
	}
	cout << maxPal << endl;
	return 0;
}
