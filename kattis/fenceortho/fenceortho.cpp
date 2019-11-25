#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

#define sq(x) x*x

struct point{
	double x, y;
	point(){}
};

point p[100000];
double dist(int i, int j){
	double dx = p[i].x - p[j].x;
	double dy = p[i].y - p[j].y;
	return 
		(double)sqrt(dx*dx + dy*dy);
}

int main(){
	cout << fixed << setprecision(6);
	int n;

	while (cin >> n){
		for (int i = 0; i < n; ++i){
			cin >> p[i].x >> p[i].y;
		}

		double maxDist = dist(0,1);
		for (int i =0 ; i < n; ++i){
			for (int j = i + 1; j < n; ++j){
				maxDist = max(maxDist, dist(i, j));
			}
		}
		
		double a = (sqrt(2)/2)*maxDist;
		cout << (double)(4*a) << endl;

	}

	return 0;
}
