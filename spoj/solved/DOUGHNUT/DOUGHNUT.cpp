#include <cstdio>
int main(){
	int t;
	scanf("%d", &t);
	while (t--){
		int c, k, w;
		scanf("%d %d %d", &c, &k, &w);
		printf("%s\n", (c*w <= k ? "yes" : "no"));
	}
	return 0;
}
