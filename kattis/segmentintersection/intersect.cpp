#include <iostream>
#include <complex>
#include <iomanip>
#include <algorithm>
using namespace std;

double eps = 1e-6;
typedef complex<double> point;
double cross(point a, point b)	{	return imag(conj(a)*b);		}
double dot (point a, point b)	{	return real(conj(a)*b);		}
double dist(point a, point b)	{	return sqrt(dot(a-b, a-b));	}

bool cmp(const point& a, const point& b){
	if (a.real() != b.real())	return a.real() < b.real();
	return a.imag() < b.imag();
}

bool segments_parallel(point a, point b, point c, point d){
	return abs(cross(a-b, c-d)) < eps;
}

bool point_on_segment(point p, point a, point b){
	if (segments_parallel(p, a, p, b) and dot(p-a, p-b) < 0)
		return true;
	return false;
}

bool segments_intersect(point a, point b, point c, point d){
	if (dist(a,c) < eps or dist(a,d) < eps or dist(b,c) < eps or dist(b,d) < eps){
		return true;
	}
	if (dist(a,b) < eps and dist(c,d) < eps)	return false;
	if (dist(a,b) < eps)	return point_on_segment(a,c,d);
	if (dist(c,d) < eps)	return point_on_segment(c,a,b);
	if (segments_parallel(a,b,c,d) and segments_parallel(a,c,b,d) and segments_parallel(a,d,b,c)){
		if (point_on_segment(a,c,d) or point_on_segment(b,c,d) or point_on_segment(c,a,b) or point_on_segment(d,a,b)){
			return true;
		}
		return false;
	}

	if (cross(a-d,a-c) * cross(a-b,a-d) > 0)	return false;
	if (cross(c-d,c-a) * cross(c-d,c-b) > 0)	return false;
	return true;
}

point lines_intersection(point a, point b, point c, point d){
	b = b - a;
	d = c - d;
	c = c - a;
	return a + b * cross(c,d) / cross(b,d);
}

void solve(point a, point b, point c, point d){
	if (!segments_intersect(a,b,c,d)){
		cout << "none" << endl;
	}
	else if (segments_parallel(a,b,c,d)){
		if (dist(a,b) < eps){
			cout << a.real() << " " << a.imag() << endl;
		}
		else if (dist(c,d) < eps){
			cout << c.real() << " " << c.imag() << endl;
		}
		else{
			point points[4];
			points[0] = a; points[1] = b; 
			points[2] = c; points[3] = d;
			sort(points, points+4, cmp);
			if (dist(points[1], points[2]) < eps){
				cout << points[1].real();
				cout << " " << points[1].imag();
			}
			else{
				cout << points[1].real() << " " << points[1].imag();
				cout << " " << points[2].real() << " "; 
				cout << points[2].imag();
			}
			cout << endl;
		}
	}
	else{
		point ans = lines_intersection(a,b,c,d);
		cout << ans.real() << " " << ans.imag() << endl;
	}
}

int main(){
	cout << fixed << setprecision(2);

	int n;
	cin >> n;

	while (n--){
		point p;
		double x1, y1, x2, y2, x3, y3, x4, y4;
		cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
		solve(point(x1,y1), point(x2,y2), point(x3,y3), point(x4,y4));
	}

	return 0;
}
