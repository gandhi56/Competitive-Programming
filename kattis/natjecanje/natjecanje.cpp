#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, s, r;
    cin >> n >> s >> r;

	int dam[n+1];
	int res[n+1];
	memset(dam, 0, sizeof(dam));
	memset(res, 0, sizeof(dam));

	for (int i = 0; i < s; ++i){
		int x;
		cin >> x;
		dam[x] = 1;
	}

	for (int i = 0; i < r; ++i){
		int x;
		cin >> x;
		res[x] = 1;
	}

	int cnt = 0;
	for (int i = 1; i <= n; ++i){
		if (dam[i]){
			if (res[i]){
				res[i] = 0;
			}
			else if (res[i-1]){
				dam[i] = 0;
				res[i-1] = 0;
			}
			else if (res[i+1]){
				res[i+1] = 0;
			}
			else{
				++cnt;
			}
		}
	}

	cout << cnt << endl;

    return 0;
}


