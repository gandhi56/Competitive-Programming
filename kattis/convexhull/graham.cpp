#include <iostream>
#include <stack>
#include <cstdlib>
#include <algorithm>
using namespace std;

#define EPS 1E-6

struct point{
	double x, y;
};

point p0;

point nextToTop(stack<point>& s){
	point p = s.top();
	s.pop();
	point res = s.top();
	s.push(p);
	return res;
}

int swap(point& p1, point& p2){
	point tmp = p1;
	p1 = p2;
	p2 = tmp;
}

double distSq(point p1, point p2){
	return (p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y);
}

int orient(point p, point q, point r){
	int val = (q.y - p.y)*(r.x - q.x) - (q.x - p.x)*(r.y - q.y);
	if (val == 0)	return 0;
	return (val > 0)	? 	1 : 2;
}

int cmp(const void *vp1, const void *vp2){
	point *p1 = (point*) vp1;
	point *p2 = (point*) vp2;
	int o = orient(p0, *p1, *p2);
	if (o == 0){
		return (distSq(p0, *p2) >= distSq(p0, *p1)) ? -1 : 1;
	}
	return (o == 2) ? -1 : 1;
}

void convexhull(point points[], int n){
	double ymin = points[0].y;
	int min = 0;
	for (int i = 1; i < n; ++i){
		double y = points[i].y;
		if ((y < ymin+EPS) || 
			(fabs(ymin-y) <= EPS and 
			fabs(points[i].x-points[min].x <= EPS)){
			ymin = points[i].y;
			min = i;
		}
	}

	swap(points[0], points[min]);

	p0 = points[0];
		sort(points++, points+n, );
}
