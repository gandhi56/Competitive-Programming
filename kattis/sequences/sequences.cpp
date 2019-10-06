
#define MOD 1000000007

#include <iostream>
using namespace std;

typedef unsigned long long ull;

int main(){
	string ss;
	cin >> ss;

	ull countQ = 0;
	ull count0 = 0;
	ull count1 = 0;

	ull prev = 1;
	ull pow2 = 1;
	ull total = 0;

	for (auto c : ss){
		if (c == '0'){
			if (countQ){
				total = (total + (count1*(pow2%MOD) + (prev*countQ%MOD))) % MOD;
			}
			else{
				total = (total+count1) % MOD;
			}

		}
		else if (c == '?'){
			total = (((total<<1) % MOD) + (count1 * pow2 % MOD)) % MOD;
			total = (total + (countQ * (prev)) % MOD) % MOD;
			countQ++;
			prev = pow2;
			pow2 <<= 1;
			pow2 %= MOD;
		}
		else if (c == '1'){
			count1++;
		}
	}
	cout << total%MOD << endl;

	return 0;
}
