#include <iostream>
#include <cstring>
#include <bitset>
using namespace std;

#define MAXN 1000001

bitset<MAXN> ishprime;
int count[MAXN];

int solve(int a, int b){
	int num = 0;
	
	while ((a-1)%4 != 0)	a++;
	while (a <= b){
		
		a+= 4;
	}
}

int main(){
	memset(count, 0, sizeof(count));
	ishprime.reset();

	for (int num = 5; num <= MAXN; num += 4){
		// is num a product of two h numbers?
	}
	
	
	int h;
	while (cin >> h){
		
	}

	return 0;
}
