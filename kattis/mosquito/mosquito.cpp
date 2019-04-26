#include <cstdio>
int main(){
	int m, p, l, e, r, s, n;
	while (scanf("%d %d %d %d %d %d %d", &m, &p, &l, &e, &r, &s, &n) == 7){
		while (n--){
			int tmp = p;
			p = l / r;
			l = e * m;
			m = tmp / s;
		}

		printf("%d\n", m);
	}

	return 0;
}
