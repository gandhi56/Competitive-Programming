#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

typedef pair<int,int> pii;

#define f first
#define s second

int n, mx, ans;
map< pair<pii, int>, int > m;
pii p[1010];

pair<pii, int> getline(pii a, pii b){
	pii z = {b.f - a.f, b.s - a.s};
	swap(z.f, z.s);
	z.f *= -1;

	int g = __gcd(z.f, z.s);
	z.f /= g;
	z.s /= g;
	if (z.f < 0 || (z.f == 0 and z.s < 0)){
		z.f *= -1;
		z.s *= -1;
	}
	return {z, z.f*a.f+z.s*a.s};
}

void solve(){
	mx = ans = 0;
	m.clear();
	for (int i = 0; i < n; ++i){
		cin >> p[i].f >> p[i].s;
	}

	for (int i = 0; i < n; ++i){
		for (int j = i+1; j < n; ++j){
			m[getline(p[i], p[j])]++;
		}
	}
	for (auto a : m){
		mx = max(mx, a.s);
	}

	for (int i = 1; i < n+1; ++i){
		if (i*(i-1)/2 <= mx){
			ans = i;
		}
	}
	cout << ans << endl;
}

int main(){
	while (cin >> n){
		if (n == 0)	break;
		solve();
	}

	return 0;
}
