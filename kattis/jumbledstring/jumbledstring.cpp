#include <iostream>
using namespace std;

int main(){
	int a, b, c, d;
	cin >> a >> b >> c >> d;

	int bb = 0, cc = 0;

	string bits("");
	if (a == 0)	{	bits = "0";		bb = 1;	}
	if (a == 1)	{	bits = "00";	bb = 2;	}
	if (a > 1){
		for (int i = 0; i < a; ++i)	{	bits += "0";	bb++;	}
	}

	int tmp = 0;
	if (d == 0)	{	bits += "1";	tmp = 1;	}
	if (d == 1)	{	bits += "11";	tmp = 2;	}
	if (d > 1){
		for (int i = 0; i < d; ++i)	{	bits += "1";	tmp++;	}
	}

	int x = bb * tmp;

	if (x < b){
		cout << "impossible" << endl;
	}
	else{
		while (x > b){
			for (int i = bb; i < bits.length(); ++i){
				int diff = x - b;
				bits[i] = '0';
				if (diff <= i){
					bits[i-x+b] = '1';
				}
				else{
					bits[0] = '1';

				}
			}
		}
	}

	cout << bits << endl;

	return 0;
}
