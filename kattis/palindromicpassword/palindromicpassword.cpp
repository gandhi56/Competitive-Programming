#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int digit(int num, int i){
	return (num % (int)pow(10, i)/pow(10, i-1));
}

bool is_pal(int num){
	for (int i = 1; i <= 3; ++i){
		if (digit(num, i) != digit(num, 6-i+1))	return false;
	}
	return true;
}

int main(){
	int n;
	cin >> n;

	vector<int> pals;
	for (int x = 100000; x <= 999999; ++x){
		if (is_pal(x)){
			pals.push_back(x);
		}
	}

	while (n--){
		int x;
		cin >> x;

		if (is_pal(x)){
			cout << x << endl;
		}
		else{
			int ans;
			int mindiff = 9999999;
			for (auto y : pals){
				int diff = abs(x - y);
				if (diff < mindiff){
					mindiff = diff;
					ans = y;
				}
			}
			cout << ans << endl;
		}
		
	}

	return 0;
}
