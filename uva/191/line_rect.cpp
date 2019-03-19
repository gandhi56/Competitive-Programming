#include <iostream>
#include <complex>
using namespace std;
typedef complex<double> point;

#define eps 1e-6

double cross(point a, point b){	return imag(conj(a)*b);	}
double dot(point a, point b){	return real(conj(a)*b);	}

int line_line(point a, point b, point c, point d, point& p){
	if (fabs(cross(b-a, d-c)) > eps){
		p = cross(c-a, d-c) / cross(b-a, d-c) * (b-a) + a;
		return 1;
	}
	if (fabs(cross(b-a, b-c)))	return 0;
	return -1;
}

int seg_seg(point a, point b, point c, point d, point& p){
	int s = line_line(a, b, c, d, p);
	if (s == 0)	return 0;
	if (s == -1){
		if (dot(a-c, a-d) < eps){
			return 2;
		}
		if (dot(b-c, b-d) < eps){
			return 2;
		}
		if (dot(c-a, c-b) < eps){
			return 2;
		}
		return -1;
	}
	if (dot(p-a, p-b) < eps and dot(p-c, p-d) < eps)	return 1;
	return -2;
}

int main(){
	int n;
	cin >> n;

	while (n--){
		int xstart,ystart, xend, yend, xleft, ytop, xright, ybottom;
		cin >> xstart >> ystart >> xend >> yend >> xleft >> ytop;
		cin >> xright, ybottom;

		point p(xstart, ystart);
		point q(xend, yend);
		point a(xleft, ytop);
		point b(xleft, ybottom);
		point c(xright, ytop);
		point d(xright, ybottom);

		point tmp;

		if (seg_seg(p, q, a, b, tmp) or seg_seg(p, q, a, c, tmp)){
			cout << "T" << endl;
			continue;
		}
		if (seg_seg(p, q, b, d, tmp) or seg_seg(p, q, c, d, tmp)){
			cout << "T" << endl;
			continue;
		}
		cout << "F" << endl;

	}

	return 0;
}

