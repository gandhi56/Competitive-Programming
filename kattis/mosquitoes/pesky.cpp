#include <bits/stdc++.h>
using namespace std;

#define MAXN 100
#define EPS 1E-5

typedef complex<double> point;

point points[MAXN];
double dis[MAXN][MAXN];

// max number of points that can lie inside the circle
// of radius 'r' being rotated about point 'i'
int getPointsInside(int i, double r, int n){
	vector< pair<double,bool> > angles;
	for (int j = 0; j < n; ++j){
		if (i != j and dis[i][j] <= 2*r){
			double B = acos(dis[i][j]/(2*r));
			double A = arg(points[j]-points[i]);
			double alpha = A-B;
			double beta = A+B;
			angles.push_back(make_pair(alpha, true));
			angles.push_back(make_pair(beta, false));
		}
	}

	sort(angles.begin(), angles.end());

	int count = 1, res = 1;
	vector< pair<double,bool> >::iterator it;
	for (it = angles.begin(); it != angles.end(); ++it){
		if (it->second){
			count++;
		}
		else{
			count--;
		}

		if (count > res){
			res = count;
		}
	}

	return res;
}

int maxPoints(point points[], int n, double r){
	for (int i = 0; i < n-1; ++i){
		for (int j = i + 1; j < n; ++j){
			dis[i][j] = dis[j][i] = abs(points[i] - points[j]) + EPS;
		}
	}

	int ans = 0;
	for (int i = 0; i < n; ++i){
		ans = max(ans, getPointsInside(i, r, n));
	}

	return ans;
}

int main(){
	
	int n;
	while (cin >> n){
		string s;
		getline(cin,s);
		while (1){

			getline(cin,s);

			int m;
			double d;
			cin >> m >> d;

			double r = d / 2.0;
			for (int i = 0; i < m; ++i){
				double x, y;
				cin >> x >> y;
				points[i] = point(x, y);
			}

			cout << maxPoints(points, m, r) << endl;
		}
	}
	
	return 0;
}

