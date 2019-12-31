#include <iostream>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;

int main(){
    int n;
    cin >> n;

    ull c[n];
    for (int i =0; i < n; ++i)  cin >> c[i];
	
	ull lo = 0;
	ull hi = 1e10;
	ull mid, ans;
	while (lo < hi){
		mid = (lo+hi)/2;
		int count = 0;
		for (int i =0; i < n; ++i){
			if (c[i] >= mid)	count++;
		}

		if (count < mid){
			hi = mid;
		}
		else{
			ans = mid;
			lo = mid+1;
		}
	}
	
	cout << ans << endl;

	return 0;
}
