#include <iostream>
#include <vector>
#include <complex>
using namespace std;

#define eps 0.00000001

typedef complex<long double> point;

int main(){
	int m;
	cin >> m;

	while (m--){
		long double x, y;
		cin  >> x >> y;
		point book(x, y);

		int n;
		cin >> n;

		vector<point> pts;

		for (int i = 0; i < n; ++i){
			cin >> x >> y;
			pts.push_back(point(x, y));
		}

		bool yes = false;
		for (auto x : pts){
			if (abs(x - book) <= 8.0){
				yes = true;
				break;
			}
		}
		cout << (yes? "light a candle" : "curse the darkness") << endl;
	}
	return 0;
}
