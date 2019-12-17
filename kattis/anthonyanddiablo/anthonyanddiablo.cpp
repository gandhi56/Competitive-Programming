#include <iostream>
#include <cmath>
using namespace std;

#define PI M_PI

int main(){

	double a, n;
	cin >> a >> n;

	double r = n / (2*PI);
	if (PI * (n/(2*PI))*(n/(2*PI)) >= a){
		cout << "Diablo is happy!" << endl;
	}
	else{
		cout << "Need more materials!" << endl;
	}

	return 0;
}
