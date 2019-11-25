#include <cstdio>
#include <cmath>

#define BOUNDARY -1
#define EPS 1E-8
#define SQR(x) ((x)*(x))

typedef struct{
	double x, y;
}point;

double dist2d(point a, point b){
	return sqrt(SQR(a.x-b.x) + SQR(a.y-b.y));
}

int pt_in_poly(point* p, int n, point a){
	int i, j, c = 0;

	for (i=0, j=n-1; i < n; j = i++){
		if (dist2d(p[i],a)+dist2d(p[j], a) - dist2d(p[i], p[j]) < EPS)
			return BOUNDARY;
		if ((((p[i].y<=a.y) && (a.y<p[j].y)) ||
         	((p[j].y<=a.y) && (a.y<p[i].y))) &&	(a.x < (p[j].x-p[i].x) * (a.y - p[i].y) / (p[j].y-p[i].y) + p[i].x)) c = !c;
	}

	return c;
}

int main(){
	int n;

	while (scanf("%d", &n) != EOF){
		if (n == 0)	break;
		point p[n];
		for (int i = 0; i < n; ++i){
			scanf("%lf %lf", &p[i].x, &p[i].y);
		}

		int m;
		scanf("%d", &m);
		while (m--){
			point a;
			scanf("%lf %lf", &a.x, &a.y);
			int ans = pt_in_poly(p, n, a);
			if (ans == BOUNDARY){
				printf("on\n");
			}
			else if (ans == 1){
				printf("in\n");
			}
			else{
				printf("out\n");
			}
		}
	}
}
