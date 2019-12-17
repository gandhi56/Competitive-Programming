#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	int w[n];
	for (int i = 0 ; i < n; ++i)	cin >> w[i];
	
	bool res[2001];
	memset(res, 0, sizeof(res));
	res[0] = true;

	for (int i =0 ; i < n; ++i){
		int top = 2001-w[i];
		for (int j = top; j >= 0; --j){
			if (res[j]){
				res[j+w[i]] = true;
			}
		}
	}

	for (int i = 0; i < 2001; ++i){
		if (res[1000+i]){
			cout << 1000+i << endl;
			break;
		}
		else if (res[1000-i]){
			cout << 1000-i << endl;
			break;
		}
	}

	return 0;
}
