#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-5;

typedef complex<double> point;
typedef pair<point, point> line;

double cross(point a, point b)	{	return imag(conj(a)*b);	}

int line_line_inter(point a, point b, point c, point d, point& p){
	if (abs(cross(b-a, d-c)) > eps){
		p = cross(c-a, d-c) / cross(b-a, d-c) * (b-a) + a;
		return 1;
	}
	if (abs(cross(b-a, b-c)) > eps)	return 0;
	return -1;
}

double per(point a, point b, point c){
	return abs(a-b) + abs(b-c) + abs(a-c);
}

int main(){
	int n;
	cin >> n;

	line l[n];
	for (int i = 0; i < n; ++i){
		double x, y;
		cin >> x >> y;
		l[i].first = point(x, y);
		cin >> x >> y;
		l[i].second = point(x, y);
	}

	double ans = 0;

	for (int i = 0; i < n; ++i){
		for (int j = i+1; j < n; ++j){
			for (int k = j+1; k < n; ++k){
				point p1, p2, p3;
				if (
				line_line_inter(l[i].first, l[i].second, l[j].first, l[j].second, p1) and
				line_line_inter(l[k].first, l[k].second, l[j].first, l[j].second, p2) and
				line_line_inter(l[i].first, l[i].second, l[k].first, l[k].second,  p3)){
					ans = max(ans, per(p1, p2, p3));
				}
			}
		}
	}

	if (ans == 0){
		cout << "no triangle" << endl;
	}
	else{
		cout << fixed << setprecision(8);
		cout << ans << endl;
	}

	return 0;
}
