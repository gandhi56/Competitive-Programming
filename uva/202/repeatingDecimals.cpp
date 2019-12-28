#include <iostream>
#include <cstring>
using namespace std;

int main(){
	int n, m;

	while (cin >> n >> m){
		int rep[4000], i, j;
		char num[4000];
		char* N = num + 1;
		memset(rep, 0, sizeof(rep));
		cout << n << "/" << m << " = " << n/m << ".";
		n %= m;
		rep[n] = 1;
		n *= 10;

		i = 2;
		while (1){
			*N = n/m + '0';	N++;
			if (rep[n%m])	break;
			rep[n%m] = i;
			n %= m;
			n *= 10;
			i++;
		}

		int k = rep[n%m], l = i;
		for (j = 1; j < l and j <= 50; ++j){
			if (j == k)	cout << "(";
			cout << num[j];
		}
		if (j < l)	cout << "...";
		cout << ")" << endl;
		cout << "   " << l-k << " = number of digits in repeating cycle";
		cout << endl << endl;
	}

	return 0;
}
