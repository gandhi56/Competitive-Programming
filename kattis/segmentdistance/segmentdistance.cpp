#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

#define EPS 1E-5

struct pt{
	double x, y;
};

int orient(pt a, pt b, pt c){
	int val = (b.y - a.y) * (c.x - b.x) - (b.x - a.x) * (c.y - b.y);
	if (fabs(val) < EPS)	return 0;	// colinear
	return val>0? 1 : 2;	// cw or ccw
}

// c on line ab
bool ptonline(pt a, pt b, pt c){
	if (orient(a, b, c) == 0){
		if (min(a.x, b.x) <= c.x and c.x <= max(a.x, b.x)){
			if (min(a.y, b.y) <= c.y and c.y <= max(a.y, b.y)){
				return true;
			}
			else	return false;
		}
		else	return false;
	}
	return false;
}

bool intersect(pt p1, pt p2, pt p3, pt p4){
	int o1 = orient(p1, p2, p3);
	int o2 = orient(p1, p2, p4);
	int o3 = orient(p3, p4, p1);
	int o4 = orient(p3, p4, p2);
	if (o1 != o2 and o3 != o4)	return true;
	if (o1 == 0 and ptonline(p1, p2, p3))	return true;
	if (o2 == 0 and ptonline(p1, p2, p4))	return true;
	if (o3 == 0 and ptonline(p3, p4, p1))	return true;
	if (o4 == 0 and ptonline(p3, p4, p2))	return true;
	return false;
}

double seg_pt_dist(pt p1, pt p2, pt p3){
	double dx = p2.x - p1.x;
	double dy = p2.y - p1.y;

	if (dx == 0 and dy == 0){
		return sqrt((p3.x-p1.x)*(p3.x-p1.x)+
					(p3.y-p1.y)*(p3.y-p1.y));
	}

	double u = ((p3.x - p1.x) * dx + 
				(p3.y - p1.y) * dy) / (dx*dx + dy*dy);
	double x, y;
	if (u < 0){
		x = p1.x;
		y = p1.y;
	}
	else if (u > 1){
		x = p2.x;
		y = p2.y;
	}
	else{
		x = p1.x + u*dx;
		y = p1.y + u*dy;
	}

	return sqrt((p3.x - x)*(p3.x-x) + (p3.y-y)*(p3.y - y));
}

double seg_seg_dist(pt p1, pt p2, pt p3, pt p4){
	if (intersect(p1, p2, p3, p4))	return 0.0;
	double d1 = seg_pt_dist(p1, p2, p3);
	double d2 = seg_pt_dist(p1, p2, p4);
	double d3 = seg_pt_dist(p3, p4, p1);
	double d4 = seg_pt_dist(p3, p4, p2);
	return min(d1, min(d2, min(d3, d4)));
}

int main(){
	cout << fixed << setprecision(2);

	int t;
	cin >> t;

	while (t--){
		pt a, b, c, d;
		cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> d.x >> d.y;
		double dist = seg_seg_dist(a, b, c, d);
		cout << dist << endl;
	}

	return 0;
}
