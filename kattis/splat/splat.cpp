#include <iostream>
#include <cmath>
#include <string>
#define EPS 1e-8
using namespace std;

struct Splat{
	double x, y, r;
	string color;
};

int main(){

	int c;
	cin >> c;

	Splat splats[105];
	while (c--){
		int n;
		cin >> n;

		for (int i = 0; i < n; ++i){
			double v;
			cin >> splats[i].x >> splats[i].y >> v 
				>> splats[i].color;
			splats[i].r = sqrt( v / acos(-1.0));
		}

		int m;
		cin >> m;
		while (m--){
			double x, y;
			cin >> x >> y;

			string col = "white";

			for (int i = n - 1; i >= 0; --i){
				double dx = x - splats[i].x;
				double dy = y - splats[i].y;
				if (dx*dx + dy*dy <= splats[i].r*splats[i].r + EPS){
					col = splats[i].color;
					break;
				}
			}
			cout << col << endl;

		}
	}

	return 0;
}
