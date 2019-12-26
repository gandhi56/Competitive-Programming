#include <iostream>
#include <cmath>
using namespace std;

int main(){
	int n, k;
	cin >> n >> k;
	int out = 1;
	int times[n];
	int fi = 0;
	int tmp =1;
	cin >> times[0];
	for (int i = 1; i < n; ++i){
		cin >> times[i];
		while (times[fi] + 1000 <= times[i]){
			fi++;
			tmp--;
		}
		tmp++;
		out = max(out, tmp);
	}
	cout << ceil(1.0*out/k) << endl;
	return 0;
}
