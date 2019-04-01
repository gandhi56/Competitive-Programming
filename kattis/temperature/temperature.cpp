#include <iostream>
#include <iomanip>
using namespace std;
int main(){
	cout << fixed;
	double x, y;
	cin >> x >> y;
	if (x == 0 and y == 1){
		cout << "ALL GOOD" << endl;
	}
	else if (y == 1){
		cout << "IMPOSSIBLE" << endl;
	}
	else{
		cout << setprecision(9);
		cout << (double)(x/(1-y)) << endl;
	}
	return 0;
}
