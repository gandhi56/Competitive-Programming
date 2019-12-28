#include <iostream>
using namespace std;

void solve(int year){
	if (year == 1918){	cout << "26.09.1918" << endl;	}
	else if (((year <= 1917)&(year%4 == 0)) or 
		((year > 1918)&(year%400 == 0) or ((year%4==0)&(year%100 != 0)))){
		cout << "12.09." << year << endl;
	}
	else{
		cout << "13.09." << year << endl;
	}
}

int main(){
	int year;
	cin >> year;

	solve(year);


	return 0;
}
