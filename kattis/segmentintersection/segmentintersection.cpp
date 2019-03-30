#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

const double EPS = 1E-6;

struct pt{
	double x, y;
	bool operator<(const pt& p)	const	{
		return x < p.x - EPS || (abs(x - p.x) < EPS && y < p.y - EPS);
	}
};

struct line{
	double a, b, c;
	line(){}
	line(pt p, pt q){
		a = p.y - q.y;
		b = q.x - p.x;
		c = -a * p.x - b * p.y;
		norm();
	}

	void norm(){
		double z = sqrt(a*a + b*b);
		if (fabs(z) > EPS){
			a /= z, b /= z, c /= z;
		}
	}

	double dist(pt p)	const	{
		return a*p.x + b*p.y + c;
	}
};

double det(double a, double b, double c, double d){
	return a*d - b*c;
}

inline bool betw(double l, double r, double x){
	return min(l, r) <= x + EPS and x <= max(l, r) + EPS;
}

inline bool intersect(double a, double b, double c, double d){
	if (a > b)	swap(a, b);
	if (c > d)	swap(c, d);
	return max(a, c) <= min(b, d) + EPS;
}

bool solve(pt a, pt b, pt c, pt d, pt& left, pt& right){
	if (!intersect(a.x, b.x, c.x, d.x) || 
		!intersect(a.y, b.y, c.y, d.y))	
		return false;
	line m(a, b);
	line n(c, d);
	double zn = det(m.a, m.b, n.a, n.b);
	if (fabs(zn) < EPS){
		if (fabs(m.dist(c)) > EPS || fabs(n.dist(a)) > EPS)
			return false;
		if (b < a)	swap(a, b);
		if (d < c)	swap(c, d);
		left = max(a, c);
		right = min(b, d);
		return true;
	}
	else{
		left.x = right.x = -det(m.c, m.b, n.c, n.b) / zn;
		left.y = right.y = -det(m.a, m.c, n.a, n.c) / zn;
		return betw(a.x, b.x, left.x) && betw(a.y, b.y, left.y) &&
				betw(c.x, d.x, left.x) && betw(c.y, d.y, left.y);
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cout << fixed << setprecision(2);

	int n;
	cin >> n;

	while (n--){
		pt a, b, c, d, l, r;
		cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> d.x >> d.y;
		
		if (solve(a, b, c, d, l, r)){
			if (fabs(l.x - r.x) < EPS and fabs(l.y - r.y) < EPS){
				if (fabs(l.x) < EPS){
					cout << fabs(l.x) << " ";
				}
				else{
					cout << l.x << " ";
				}

				if (fabs(l.y) < EPS){
					cout << fabs(l.y) << endl;
				}
				else{
					cout << l.y << endl;
				}
			}
			else{
				if (r.x < l.x){
					swap(l, r);
				}
				else if (fabs(r.x - l.x) < EPS){
					if (r.y < l.y)	swap(l, r);
				}
				cout << l.x << " " << l.y << " ";
				cout << r.x << " " << r.y << endl;
			}
		}
		else{
			cout << "none" << endl;
		}
	}

	return 0;
}
