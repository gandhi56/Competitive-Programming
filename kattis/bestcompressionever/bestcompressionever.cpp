#include <cstdio>
int main(){
	unsigned long long n;
	int b;
	scanf("%llu %d", &n, &b);
	printf(n > (1llu << (b+1))-1 ? "no\n" : "yes\n");
	return 0;
}
