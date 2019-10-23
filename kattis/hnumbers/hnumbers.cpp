#include <bits/stdc++.h>
using namespace std;

const int maxn = 2000000;

int main(){
	vector<int> primeDivs(maxn, 0);
	vector<int> semihp(maxn, 0);

	for (int i = 0; i < maxn; ++i)
		primeDivs[i] = i;

	int facts[5];
	semihp[1] = 0;
	for (int i = 5; i < maxn; i += 4){
		if (primeDivs[i] == i){
			for (int j = 5*i; j < maxn; j += 4*i){
				primeDivs[j] = i;
			}
		}
		semihp[i] = semihp[i-4];
		if (i != primeDivs[i] and primeDivs[i/primeDivs[i]] == i/primeDivs[i]){
			++semihp[i];
		}
	}

	int x;
	while (cin >> x and x){
		cout << x << " " << semihp[x] << endl;
	}

	return 0;
}
