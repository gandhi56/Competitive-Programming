#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-9;
const int INF = 0x3f3f3f3f;

typedef vector< vector<double> > mat;

int gauss(mat a, vector<double>& ans){
  int n = (int)a.size();
  int m = (int)a[0].size() - 1;
  vector<int> where(m, -1);
  for (int col = 0, row = 0; col < m and row < n; ++col){
    int sel = row;
    for (int i = row; i < n; ++i){
      if (abs(a[i][col]) > abs(a[sel][col]))
        sel = i;
    }

    if (abs(a[sel][col]) < EPS) continue;

    for (int i = col; i <= m; ++i)
      swap(a[sel][i], a[row][i]);
    where[col] = row;

    for (int i =0 ; i < n; ++i){
      if (i != row){
        double c = a[i][col] / a[row][col];
        for (int j = col; j <= m; ++j)
          a[i][j] -= a[row][j] * c;
      }
    }
    ++row;
  }

  ans.assign(m, 0);
  for (int i = 0; i < m; ++i){
    if (where[i] != -1){
      ans[i] = a[where[i]][m] / a[where[i]][i];
    }
    else{
      ans[i] == INF;
    }
  }

  for (int i = 0; i < n; ++i){
    double sum = 0.0;
    for (int j = 0; j < m; ++j){
      sum += ans[j] * a[i][j];
    }
    if (abs(sum - a[i][m]) > EPS)
      return 0;
  }

  for (int i = 0; i < m; ++i)
    if (where[i] == -1)
      ans[i] = INF;
  return 1;

}

int main(){
  int n;
  while (cin >> n){
    if (n == 0) break;
    mat a(n);
    for (int i =0 ; i < n; ++i){
      for (int j = 0; j < n; ++j){
        double x;
        cin >> x;
        a[i].push_back(x);
      }
    }

    for (int i = 0; i < n; ++i){
      double x;
      cin >> x;
      a[i].push_back(x);
    }

    vector<double> ans(n);
    int res = gauss(a, ans);
    if (res == 0){
      cout << "inconsistent" << endl;
    }
    else{
      for (auto& x : ans) cout << x << ' ';
      cout << endl;
    }

  }
  return 0;
}