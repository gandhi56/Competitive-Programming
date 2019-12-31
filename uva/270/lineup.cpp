#include <bits/stdc++.h>
using namespace std;

typedef complex<int> point;

int cross(point a, point b){	return imag(conj(a)*b);		}

void solve(vector<point> points){
	int count = 0;
	int best = 1;
	for (int i = 0; i < points.size(); ++i){
		count = 1;
		for (int j = i + 1; j < points.size(); ++j){
			if (cross(points[i], points[j]) == 0){
				count++;
			}
		}
		best = max(best, count);
	}
	cout << best << endl;
}

int main(){
	int t, n;
	cin >> t;

	string line;
	getline(cin, line);
	getline(cin, line);

	while (t--){
		
		vector<point> points;
		while (getline(cin, line)){
			int x, y;
			if (line == "")	break;
			sscanf(line.c_str(), "%d %d", &x, &y);
			points.push_back(point(x, y));
		}

		solve(points);

		if (t)	cout << endl;
	}

	return 0;
}
