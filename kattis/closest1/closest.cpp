#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;

#define MAXN 100000

struct point{
	double x, y;
	int i;
};

bool cmpX(const point& p, const point& q){	return p.x < q.x;	}
bool cmpY(const point& p, const point& q){	return p.y < q.y;	}

point points[MAXN];
point ptsSort[MAXN];
point aux[MAXN];

int pi, pj;
double mind;

double dist(const point& p, const point& q){
	double dx = p.x - q.x;
	double dy = p.y - q.y;
	return sqrt(dx*dx + dy*dy);
}

void closestPairRec(point p[], int n){
	if (n <= 1)	return;

	int mid = n >> 1;
	closestPairRec(p, mid);
	closestPairRec(p+mid, n-mid);

	int m = 0;
	for (int i = 0; i < n; ++i){
		if (abs(p[i].x - p[mid].x) < mind){
			aux[m++] = p[i];
		}
	}

	sort(aux, aux+m, cmpY);

	for (int i =0 ; i < m; ++i){
		for (int j = i + 1; j < m and aux[j].y < aux[i].y+mind; ++j){
			double d = dist(aux[i], aux[j]);
			if (d < mind){
				mind = d;
				pi = aux[i].i;
				pj = aux[j].i;
			}
		}
	}
}

void closestPair(int n){
	for (int i = 0; i < n; ++i){
		points[i].i = i;
		ptsSort[i] = points[i];
	}

	sort(ptsSort, ptsSort + n, cmpX);

	mind = INFINITY;
	closestPairRec(ptsSort, n);
}

int main(){
	while (1){
		int n;
		cin >> n;

		if (n == 0)	break;

		for (int i =0 ; i < n; ++i){
			cin >> points[i].x >> points[i].y;
		}

		closestPair(n);
		cout << fixed << setprecision(2);
		cout << points[pi].x << " " << points[pi].y << " " << points[pj].x << ' ' << points[pj].y << endl;
	}
	return 0;
}
