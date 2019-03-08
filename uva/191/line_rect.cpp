#include <bits/stdc++.h>
using namespace std;

struct point{
	int x, y;
	point(){}
	point(int xx, int yy)	:	x(xx), y(yy)	{}
};

bool onSegment(point p, point q, point r){
	if (q.x <= max(p.x, r.x) and q.x >= min(p.x, r.x) and
		q.y <= max(p.y, r.y) and q.y >= min(p.y, r.y))
		return true;
	return false;
}

int orientation(point p, point q, point r){
	int val = (q.y - p.y) * (r.x - q.x) -
				(q.x - p.x) * (r.y - q.y);
	if (val == 0)	return 0;
	return (val > 0)	? 1 : 2;
}

bool intersect(point p1, point q1, point p2, point q2){
	int o1 = orientation(p1, q1, p2);
	int o2 = orientation(p1, q1, q2);
	int o3 = orientation(p2, q2, p1);
	int o4 = orientation(p2, q2, q1);

	if (o1 != o2 and o3 != o4)	return true;

	if (o1 == 0 and onSegment(p1, p2, q1))	return true;
	if (o2 == 0 and onSegment(p1, q2, q1))	return true;
	if (o3 == 0	and onSegment(p2, p1, q2))	return true;
	if (o4 == 0 and onSegment(p2, q1, q2))	return true;
	return false;
}

int main(){
	int n;
	cin >> n;

	for (int i =0 ; i < n; ++i){
		point p1, q1, a, b;
		cin>>p1.x >> p1.y >> q1.x >> q1.y >> a.x >> a.y >> b.x >> b.y;
		
		// line and top edge
		if (intersect(p1, q1, a, point(b.x, a.y))){
			cout << "T" << endl;
		}
		else if (intersect(p1, q1, a, point(a.x, b.y))){
			cout << "T" << endl;
		}
		else if (intersect(p1, q1, b, point(a.x, b.y))){
			cout << "T" << endl;
		}
		else if (intersect(p1, q1, b, point(b.x, a.y))){
			cout << "T" << endl;
		}
		else{
			cout << "F" << endl;
		}

	}

	return 0;
}
