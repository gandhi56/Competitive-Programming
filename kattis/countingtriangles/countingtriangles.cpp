#include <iostream>
#include <vector>
using namespace std;

struct point{
	double x, y;
	point(){}
	point(double xx, double yy)	:	x(xx), y(yy)	{}
};

typedef pair< point,point > pp;

bool intersect(point p1, point p2, point p3, point p4){
	double denom = ((p1.x-p2.x) * (p3.y - p4.y)) - ((p1.y - p2.y) * (p3.x - p4.x));
	if (denom == 0.0)	return false;
	double x = (((p1.y - p3.y)*(p4.x-p3.x)) - ((p1.x-p3.x)*(p4.y-p3.y)))/denom;
	double y = (((p1.y - p3.y)*(p2.x-p1.x)) - ((p1.x-p3.x)*(p2.y-p1.y)))/denom;
	return (x >= 0 and x <= 1) and (y >= 0 and y <= 1);
}

int main(){
	int n;
	while (cin >> n){
		
		if (n == 0)	break;

		vector< pp > l;
		for (int i = 0; i < n; ++i){
			double a, b, c, d;
			cin >> a >> b >> c >> d;
			l.push_back({ point(a, b), point(c, d) });
		}

		int ans = 0;
		for (int i = 0; i < n-2; ++i){
			for (int j = i + 1; j < n-1; ++j){
				if (!(intersect(l[i].first, l[i].second, l[j].first, l[j].second)))
					continue;
				for (int k = j + 1; k < n; ++k){
					if (!(intersect(l[i].first, l[i].second, l[k].first, l[k].second)))
						continue;

					if ((intersect(l[k].first, l[k].second, l[j].first, l[j].second)))
						ans++;

				}
			}
		}

		cout << ans << endl;

	}

	return 0;
}
