#include <iostream>
using namespace std;

int main(){
	int x;
	cin >> x;

	int n;
	cin >> n;

	int p[n];
	for (int i = 0; i < n; ++i)	cin >> p[i];

	int total = x * (n+1);
	for (int i = 0; i < n; ++i){
		total -= p[i];
	}
	
	cout << total << endl;

	return 0;
}
