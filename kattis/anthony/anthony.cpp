#include <iostream>
#include <iomanip>
#include <map>
using namespace std;

typedef pair<int,int> ii;

int N, M;
double p[4000];
map<ii,double> memo;

double solve(int n, int m){
	if (memo.find({n, m}) != memo.end())
		return memo[{n, m}];
	if (n == 0)
		return 0.0;
	if (m == 0)
		return 1.0;

	int i = N+M-n-m;
	memo[{n, m}] = p[i] * solve(n, m-1) + (1-p[i]) * solve(n-1, m);
	return memo[{n, m}];
}

int main(){
	int n, m;
	cin >> n >> m;

	N = n;
	M = m;

	for (int i = 0; i < n+m-1; ++i){
		cin >> p[i];
	}

	cout << fixed << setprecision(6);
	cout << solve(n, m) << endl;

	return 0;
}
