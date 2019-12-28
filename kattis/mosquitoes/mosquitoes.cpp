#include <iostream>
#include <cmath>
using namespace std;

#define EPS 1E-5

struct point{
	double x, y;
};

double dist(point a, point b){
	return (double)sqrt( (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y) );
}

void center(point a, point b, double r, point& c){
	point mid;
	mid.x = (double)((a.x+b.x)/2);
	mid.y = (double)((a.y+b.y)/2);
	double amid = dist(a, mid);
	double midcent = sqrt(r*r - amid*amid);
	double rad = atan2(a.x-b.x, b.y-a.y);
	c.x = midcent*cos(rad)+mid.x;
	c.y = midcent*sin(rad)+mid.y;
}

void solve(point pt[], int m, double d){
	int best = 0;
	double r = d / 2.0;
	point c;
	for (int i = 0; i < m; ++i){
		for (int j = 0; j < m; ++j){

			center(pt[i], pt[j], r, c);
			int count = 0;
			for (int k = 0; k < m; ++k){
				if (dist(c, pt[k])-EPS <= r)	count++;
			}
			best = max(best, count);
		}
	}
	cout << best << endl;
}

int main(){
	int n;
	cin >> n;
	while (n--){
		int m;
		double d;
		cin >> m >> d;

		point pt[m];
		for (int i = 0; i < m; ++i)	cin >> pt[i].x >> pt[i].y;

		solve(pt, m, d);

	}

	return 0;
}
