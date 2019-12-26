
#define EPS 1e-6
#define MAXN 2500
#include <bits/stdc++.h>
using namespace std;

typedef complex<double> point;
typedef long long ll;
vector<bool> ok(MAXN,true);
double prob;
double cross(point a, point b){		return imag(conj(a) * b);	}
double area(vector<point>& p){
	int n = p.size();
	double area = 0.0;
	for (int i = n-1, j = 0; j < n;){
		area += cross(p[i], p[j]) * 0.5;
		i = j;
		j++;
		while (!ok[j])	j++;
	}
	return area;
}


int main(){
	int n, k;
	cin >> n >> k;
	vector<point> p;
	for (int i = 0; i < n; ++i){
		double x, y;
		cin >> x >> y;
		p.push_back(point(x, y));
	}
	reverse(p.begin(), p.end());
	
	double ans = 0.0;
	for (int i = 0; i < n; ++i){
		prob = (k * (k - 1)) / 1.0 / (n * (n - 1));
	}
	return 0;
}
