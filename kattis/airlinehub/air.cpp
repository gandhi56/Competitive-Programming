#include <iostream>
#include <cmath>
#include <climits>
#include <iomanip>
using namespace std;

typedef long double ld;

double toRad(const double deg){
	return (double)(((M_PI) / 180.00) * deg);
}

struct point{
	double dlat, dlon;
	double lat, lon;
	double dist(const point& p){
		double diffLon = p.lon - lon;
		double diffLat = p.lat - lat;
		double ans = sin(diffLat/2.0)*sin(diffLat/2.0) +
					cos(lat)*cos(p.lat)*sin(diffLon/2.0)*
					sin(diffLon/2.0);
		return 2.0 * asin(ans);
	}
};

void solve(point points[], int n){
	double best = -1;
	int bestHub = 0;
	for (int i = 0; i < n; ++i){
		double maxDist = -1.0;
		for (int j = 0; j < n; ++j){
			if (i == j)	continue;
			double d = points[i].dist(points[j]);
			maxDist = max(maxDist, d);
		}
		if (maxDist <= best or best < 0){
			best = maxDist;
			bestHub = i;
		}
	}
	cout << points[bestHub].dlat << " " << points[bestHub].dlon << endl;
}

int main(){
	int n;

	cout << fixed << setprecision(2);

	while (cin >> n){
		point points[n];
		for (int i = 0; i < n; ++i){
			cin >> points[i].dlat >> points[i].dlon;
			points[i].lat = toRad(points[i].dlat);
			points[i].lon = toRad(points[i].dlon);
		}
		solve(points, n);
	}

	return 0;
}
