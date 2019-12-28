#include <iostream>
using namespace std;

typedef unsigned long long ull;

int solve(ull p, ull n, bool isMax, int alpha, int beta, int depth){

	for (int i = 0; i < depth; ++i)
		cout << '.';

	cout << p << " " << isMax << endl;
	
	int value;
	if (p >= n){
		if (isMax)
			return 1;
		return -1;
	}

	value = -100;
	for (int q = 2; q < 10; ++q){
		value = max(value, -solve(p*q, n, !isMax, -beta, -alpha, depth+1));
		alpha = max(alpha, value);
		if (alpha >= beta)
			break;
	}
	return value;

}

int main(){
	ull n;
	while (cin >> n){
		cout << solve(1, n, true, -100, 100, 0) << endl;
	}

	return 0;
}
