#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	
	int bus[n];
	for (int i = 0; i < n; ++i)	cin >> bus[i];

	sort(bus, bus+n);

	int i = 0;
	while (i < n){
		int j = i+1;
		while (bus[j]-1 == bus[j-1])	j++;
		if (j != i+1 and j-i > 2){
			cout << bus[i] << '-' << bus[j-1] << ' ';
		}
		else{
			cout << bus[i] << ' ';
			if (j == i+2){
				cout << bus[i+1] << ' ';
			}
		}
		i = j;
	}
	cout << endl;
	return 0;
}
