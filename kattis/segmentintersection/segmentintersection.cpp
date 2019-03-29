#include <iostream>
#include <complex>
#include <cassert>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

const double eps = 1e-6;
typedef complex<double> point;

double cross(point a, point b){		return imag(conj(a)*b);		}
double dot(point a, point b){		return real(conj(a)*b);		}
double dist(point a, point b){		return sqrt(dot(a-b, a-b));	}

bool segments_parallel(point a, point b, point c, point d){
	return fabs(cross(a-b, c-d)) < eps;
}

bool point_on_seg(point p, point a, point b){
	return (segments_parallel(p, a, p, b) and dot(p-a, p-b) < 0);
}

bool segments_intersect(point a, point b, point c, point d){
	if (dist(a, c) < eps or dist(a, d) < eps or dist(b, c) < eps or dist(b, d) < eps )	return true;
	if (dist(a, b) < eps and dist(c, d) < eps)	return false;
	if (dist(a, b) < eps) 	return point_on_seg(a, c, d);
	if (dist(c, d) < eps)	return point_on_seg(c, a, b);
	if (segments_parallel(a, b, c, d) and segments_parallel(a, c, b, d) and segments_parallel(a, d, b, c)){
		return (point_on_seg(a,c,d) || 
				point_on_seg(b,c,d) || 
				point_on_seg(c,a,b) || 
				point_on_seg(d,a,b));
	}
	if (cross(a-b, a-c) * cross(a-b, a-d))	return false;
	if (cross(c-d, c-a) * cross(c-d, c-b))	return false;
	return true;
}

point lines_intersect(point a, point b, point c, point d){
	b = b - a;
	d = c - d;
	c = c - a;
	assert(dot(b, b) > eps and dot(d, d) > eps);
	return a + b * cross(c, d) / cross(b, d);
}

void solve(point a, point b, point c, point d){
	if (!segments_intersect(a, b, c, d))	cout << "none" << endl;
	else if (segments_parallel(a, b, c, d)){
		if (dist(a, b) < eps){
			cout << a.real() << " " << a.imag() << endl;
		}
		else if (dist(c, d) < eps){
			cout << c.real() << " " << c.imag() << endl;
		}
		else{
			point pts[] = {a, b, c, d};
			sort(pts, pts+4);
			if (dist(pts[1], pts[2]) < eps)	
				cout << pts[1].real() << " " << pts[1].imag();
			else{
				for (int i = 1; i < 3; ++i){
					cout << pts[i].real() << " " << pts[i].imag();
				}
			}
			cout << endl;
		}
	}
	else{
		point ans = lines_intersect(a, b, c, d);
		cout << ans.real() << " " << ans.imag() << endl;
	}
}

int main(){
	int t;
	cin >> t;

	while (t--){
		int x1, y1, x2, y2, x3, y3, x4, y4;
		cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

		point a(x1, y1);
		point b(x2, y2);
		point c(x3, y3);
		point d(x4, y4);

		solve(a, b, c, d);
	}

	return 0;
}
