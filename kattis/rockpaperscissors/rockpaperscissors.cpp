#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

int main(){

	cout << fixed << setprecision(3);

	int n, k;
	bool ok = false;
	while (cin >> n >> k and n){
		if (ok)	cout << endl;
		ok = true;
		int w[n+1];
		int l[n+1];
		memset(w, 0, sizeof(w));
		memset(l, 0, sizeof(l));
		for (int m = 0; m < k*(n*(n-1))/2; ++m){
			int p1, p2;
			string m1, m2;
			cin >> p1 >> m1 >> p2 >> m2;
			if (m1 == m2)	continue;
			if (m1 == "rock" and m2 == "paper"){
				w[p2]++;
				l[p1]++;
			}
			else if (m1 == "paper" and m2 == "rock"){
				w[p1]++;
				l[p2]++;
			}
			else if (m1 == "rock" and m2 == "scissors"){
				w[p1]++;
				l[p2]++;
			}
			else if (m1 == "scissors" and m2 == "rock"){
				w[p2]++;
				l[p1]++;
			}
			else if (m1 == "scissors" and m2 == "paper"){
				w[p1]++;
				l[p2]++;
			}
			else if (m1 == "paper" and m2 == "scissors"){
				w[p2]++;
				l[p1]++;
			}
		}
		for (int i = 1; i <= n; ++i){
			if (w[i] == 0 and l[i] == 0){
				cout << "-" << endl;
			}
			else{
				cout << (double)w[i]/(w[i] + l[i]) << endl;
			}
		}
	}

	return 0;
}
