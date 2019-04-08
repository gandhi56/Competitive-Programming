#include <iostream>
#include <algorithm>
using namespace std;

int decrement(int* d, int i, int j){
	for (int k = i; k <= j; ++k){
		d[k]--;
	}
}

int foo(int diff[], int n){
	int count = 0;
	while (1){
		int maxValue = *max_element(diff, diff+n);
		if (maxValue == 0)	break;
		int start = -1;
		for (int i = 0; i < n; ++i){
			if (diff[i] == maxValue){
				if (start == -1){
					start = i;
				}
			}
			else if (start != -1){
				decrement(diff, start, i-1);
				count++;
				start = -1;
			}
		}

		if (start != -1){
			decrement(diff, start, n-1);
			count++;
		}
	}
	return count;
}

int solve(string a, string b){
	int diff[a.size()];
	for (int i = 0; i < a.size(); ++i){
		diff[i] =(int)(a[i] - b[i]);
	}
	
	int count = foo(diff, a.size());
	for (int i = 0; i < a.size(); ++i)	diff[i] *= -1;
	count += foo(diff, a.size());

	return count;
}

int main(){
	string a, b;
	cin >> a >> b;
	cout << solve(a, b) << endl;
	return 0;
}
