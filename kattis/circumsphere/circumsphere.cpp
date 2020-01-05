#include <bits/stdc++.h>
using namespace std;

vector< vector<double> > a(4, vector<double>(5,0));

const double EPS = 1e-9;
const int INF = 2; // it doesn't actually have to be infinity or a big number

int gauss (vector < vector<double> > a, vector<double> & ans) {
	int n = (int) a.size();
	int m = (int) a[0].size() - 1;

	vector<int> where (m, -1);
	for (int col=0, row=0; col<m && row<n; ++col) {
		int sel = row;
		for (int i=row; i<n; ++i)
			if (abs (a[i][col]) > abs (a[sel][col]))
				sel = i;
			if (abs (a[sel][col]) < EPS)
				continue;
		for (int i=col; i<=m; ++i)
			swap (a[sel][i], a[row][i]);
		where[col] = row;

		for (int i=0; i<n; ++i)
			if (i != row) {
				double c = a[i][col] / a[row][col];
				for (int j=col; j<=m; ++j)
					a[i][j] -= a[row][j] * c;
			}
			++row;
	}

	ans.assign (m, 0);
	for (int i=0; i<m; ++i)
	if (where[i] != -1)
	ans[i] = a[where[i]][m] / a[where[i]][i];
	for (int i=0; i<n; ++i) {
	double sum = 0;
	for (int j=0; j<m; ++j)
	sum += ans[j] * a[i][j];
	if (abs (sum - a[i][m]) > EPS)
	return 0;
	}

	for (int i=0; i<m; ++i)
	if (where[i] == -1)
	return INF;
	return 1;
}





void show(){
  for (auto& v : a){
    for (auto& x : v){
      cout << x << ' ';
    }
    cout << endl;
  }
}

int main(){
  cout << fixed << setprecision(6);
  for (int i = 0; i < 4; ++i){
    double x, y, z;
    cin >> x >> y >> z;

    a[i][0] = -2*x;
    a[i][1] = -2*y;
    a[i][2] = -2*z;
    a[i][3] = -1.0;
    a[i][4] = -1*(x*x + y*y + z*z);

  }

  vector<double> ans(4, 0);
  gauss(a, ans);
  for (int i = 0; i < 3; ++i) cout << ans[i] << ' ';
  cout << endl;
  return 0;
}

