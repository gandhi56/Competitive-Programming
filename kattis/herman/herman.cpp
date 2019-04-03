#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main(){
	cout  << fixed << setprecision(6);
	long double r;
	cin >> r;
	cout << M_PI * r * r << endl;
	cout << 2*r*r << endl;
	return 0;
}
