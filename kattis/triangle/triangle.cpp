#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
	int t = 1, n;
	while (scanf("%d", &n) != EOF){
		int d = 1 + floor((n+1) * log10(3) - n * log10(2));
		printf("Case %d: %d\n", t, d);
		t++;
	}

	return 0;
}
