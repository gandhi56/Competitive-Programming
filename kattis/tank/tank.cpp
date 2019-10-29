
#define EPS 1e-5

#include <bits/stdc++.h>
using namespace std;

typedef complex<double> point;
typedef pair<double,double> dd;
double cross(const point& a, const point& b){	return imag(conj(a)*b);		}

double area(vector<point>& p){
	double area = 0.0;
	for (int i = p.size() - 1, j = 0; j < p.size(); i = j++)
		area += cross(p[i], p[j]) / 2.0;
	return area;
}

bool cmp(point& a , point& b){
	return arg(a) < arg(b);
}

int main(){
	cout << fixed << setprecision(2);
	int n, d, l;
	cin >> n >> d >> l;

	double lo = 3000.0;
	double hi = -3000.0;
	vector<point> poly;	// points in ccw order
	vector<point> p;	// points in ccw order
	vector<point> base;	// points in ccw order

	// input all points
	while (n--){
		double x, y;
		cin >> x >> y;
		poly.push_back(point(x, y));
		hi = max(hi, y);
		lo = min(lo, y);
	}
	sort(poly.begin(), poly.end(), cmp);

	// check if the full tank needs to be filled
	if (area(poly)*d == l){
		cout << hi << endl;
		return 0;
	}

	for (auto& pp : poly){
		if (pp.imag() == lo){
			p.push_back(pp);	// points on the base of the tank
			base.push_back(pp);
		}
	}

	// binary search
	double A = (l * 1000.0) / d;	// target area
	double mid;
	cout << "lo = " << lo << endl;
	cout << "hi = " << hi << endl;
	cout << "A = " << A << endl;
	while (lo < hi){
		mid = (lo + hi) / 2.0;
		// intersection between y = mid and poly
		dd ip;
		for (int i = 0;  i < poly.size(); ++i){
			point c = poly[i];
			point d = poly[(i+1) % poly.size()];
			//int res = intersect_line(point(-2000.0, mid), point(2000.0, mid), c, d, ip);
			//if (res == 1){
			//	// ip stores the intersection point
			//	p.push_back(point(ip.first, ip.second));
			//}
			//else if (res == -1){
			//	// should never enter here!
			//	p.push_back(highPoints[0]);
			//	p.push_back(highPoints[1]);
			//}

			if (c.imag() < d.imag()){
				if (mid < c.imag()){
					continue;
				}
				else if (mid == c.imag()){
					p.push_back(c);
				}
				else if (c.imag() < mid){
					p.push_back(c);
					if (mid == d.imag()){
						p.push_back(d);
					}
					else if (d.imag() < mid){
						p.push_back(d);
						p.push_back(mid);	//
						
						ip.first = (mid - c.imag()) * (d.real() - c.real()) / (d.imag() - c.imag()) + c.real();
						ip.second = mid;
						p.push_back(point(ip.first, ip.second));
					}
				}
			}
			else if (d.imag() < c.imag()){
				if (mid < d.imag()){
					continue;
				}
				else if (mid == d.imag()){
					p.push_back(d);
				}
				else if (d.imag() < mid){
					p.push_back(d);
					if (mid == c.imag()){
						p.push_back(c);
					}
					else if (c.imag() < mid){
						p.push_back(c);
						p.push_back(mid);	//
					}
				}
			
			}

			if (c.imag() < mid and mid < d.imag()){
				// there is an intersection point
				ip.first = (mid - c.imag()) * (d.real() - c.real()) / (d.imag() - c.imag()) + c.real();
				ip.second = mid;
				p.push_back(point(ip.first, ip.second));
			}
			else if (d.imag() < mid and mid < c.imag()){
			
				ip.first = (mid - d.imag()) * (c.real() - d.real()) / (c.imag() - d.imag()) + d.real();
				ip.second = mid;
				p.push_back(point(ip.first, ip.second));
			}
			else if (d.imag() < mid and c.imag() < mid){
				if (c.imag() < d.imag()){
					p.push_back(c);
					p.push_back(d);
				}
				else{
					p.push_back(d);
					p.push_back(c);
				}
			}

		}

		double a = area(p);
		cout << "height = " << mid << " "  << lo << " " << hi << " a = " << a << endl;	// guessed height
		if (a < A){
			lo = mid + EPS;
		}
		else if (a > A){
			hi = mid - EPS;
		}
		else{
			break;
		}
		p.clear();
		p.push_back(base[0]);
		p.push_back(base[1]);
	}
	cout << mid << endl;
	return 0;
}
