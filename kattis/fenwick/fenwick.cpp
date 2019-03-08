#include <cstdio>
using namespace std;

typedef long long ll;

int n, q, i;
char c;
ll d;
ll bit[5000001];

inline void update(int x, ll v){
	for (; x <= n; x += x&-x)	bit[x] += v;
}

inline ll sum(int x){
	ll total = 0;
	for (; x > 0; x -= x&-x)	total += bit[x];
	return total;
}

int main(){
	scanf("%d%d", &n, &q);
	while (q--){
		scanf(" %c", &c);
		if (c == '+'){
			scanf("%d%lld", &i, &d);
			update(i+1, d);
		}
		else{
			scanf("%d", &i);
			if (i){	
				printf("%lld\n", sum(i));
			}
			else{	
				printf("0\n");
			}
		}
	}
	return 0;
}
