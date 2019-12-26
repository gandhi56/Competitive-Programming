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
	int deg[n];
	int unknowns = 0;
	for (int i = 0; i < n; ++i){
		cin >> x[i] >> y[i];
		if (x[i] == -1)	unknowns++;
		deg[i] = 0;
	}

	bool adj[n][n];
	memset(adj, 0, sizeof(adj));
	for (int i =0 ; i < m; ++i){
		int a, b;
		cin >> a >> b;
		adj[--a][--b] = true;
		adj[b][a] = true;
		deg[a]++;
		deg[b]++;
	}

	// solve for x coordinates
	vector< vector<double> > a(n);
	for (int i = 0; i < n; ++i){
		if (x[i] == -1){
			double val = 0;
			for (int j = 0; j < n; ++j){
				if (i == j){
					a[i].push_back(deg[i]);
				}
				else if (adj[i][j]){
					if (x[j] == -1){
						a[i].push_back(-1);
					}
					else{
						a[i].push_back(0);
						val += x[j];
					}
				}
				else{
					a[i].push_back(0);
				}
			}
			a[i].push_back(val);
		}
		else{
			// x[i] is known, set a[i][i] to 1 and b[i] = x[i]
			for (int j = 0; j < n; ++j){
				a[i].push_back(0);
			}
			a[i][i] = 1;
			a[i].push_back(x[i]);
		}
	}

	vector<double> xx(n);
	gauss(a, xx);
	for (int i =0 ; i < n; ++i){
		x[i] = xx[i];
	}


	// solve for y coordinates
	vector< vector<double> > b(n);
	for (int i = 0; i < n; ++i){
		if (y[i] == -1){
			double val = 0;
			for (int j = 0; j < n; ++j){
				if (i == j){
					b[i].push_back(deg[i]);
				}
				else if (adj[i][j]){
					if (y[j] == -1){
						b[i].push_back(-1);
					}
					else{
						b[i].push_back(0);
						val += y[j];
					}
				}
				else{
					b[i].push_back(0);
				}
			}
			b[i].push_back(val);
		}
		else{
			// x[i] is known, set a[i][i] to 1 and b[i] = x[i]
			for (int j = 0; j < n; ++j){
				b[i].push_back(0);
			}
			b[i][i] = 1;
			b[i].push_back(y[i]);
		}
	}

	vector<double> yy(n);
	gauss(b, yy);
	for (int i =0 ; i < n; ++i){
		y[i] = yy[i];
	}

	for (int i = 0; i < n; ++i){
		cout << x[i] << ' ' << y[i] << endl;
	}
	return 0;
}
