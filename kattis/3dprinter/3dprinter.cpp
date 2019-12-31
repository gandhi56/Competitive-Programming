#include <cstdio>
#include <cmath>
int main(){
	int n;
	scanf("%d", &n);
	printf("%d\n", (int)ceil(log2(n))+1);
	return 0;
}
