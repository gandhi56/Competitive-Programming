#include <iostream>
#include <algorithm>
using namespace std;
typedef unsigned long long ull;
int main(){
	ull n;
	cin >> n;
  	cout << (n==0? 1 : (1LL<<(64 - __builtin_clzl(n) - __builtin_popcountl(n)))) << endl;
	return 0;
}

