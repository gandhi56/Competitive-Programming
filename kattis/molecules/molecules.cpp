#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-9;
const int INF = 2;

int gauss(vector< vector<double> > a, vector<double>& ans){
	int n = a.size();
	int m = a[0].size() - 1;

	vector<int> where(m, -1);
	for (int col = 0, row = 0; col < m and row < n; ++col){
		int sel = row;
		for (int i = row; i < n; ++i){
			if (abs(a[i][col]) > abs(a[sel][col]))	sel = i;
		}
		if (abs(a[sel][col]) < EPS)	continue;
		for (int i = col; i <= m; ++i)	swap(a[sel][i], a[row][i]);
		where[col] = row;

		for (int i = 0; i < n; ++i){
			if (i != row){
				double c = a[i][col] / a[row][col];
				for (int j = col; j <= m; ++j)	a[i][j] -= a[row][j] * c;
			}
		}
		++row;
	}

	ans.assign(m, 0);
	for (int i = 0; i < m; ++i){
		if (where[i] != -1)	ans[i] = a[where[i]][m] / a[where[i]][i];
	}

	for (int i =0 ; i < n; ++i){
		double sum = 0.0;
		for (int j = 0; j < m; ++j)	sum += ans[j] * a[i][j];
		if (abs(sum - a[i][m]) > EPS)	return 0;
	}

	for (int i = 0; i < m; ++i){
		if (where[i] == -1)	return INF;
	}
	return 1;
}

int main(){

	cout << fixed << setprecision(5);

	int n, m;
	cin >> n >> m;
	double x[n], y[n];
	int unknowns = 0;
	for (int i = 0; i < n; ++i){
		cin >> x[i] >> y[i];
		if (x[i] == -1)	unknowns++;
	}

	vector< vector<int> > g(n);
	for (int i =0 ; i < m; ++i){
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	// solve for x coordinates
	unordered_map< int, vector<double> > a(unknowns);
	for (int i = 0; i < n; ++i){
		if (x[i] != -1)	continue;
		// point i has an unknown location
		
	}

	return 0;
}
