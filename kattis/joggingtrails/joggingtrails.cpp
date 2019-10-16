
#define MAXN 20
#define DISC -1

#include <iostream>
#include <cstring>
using namespace std;

int g[MAXN][MAXN];
int deg[MAXN];
int a[MAXN+1];
int sum;
int odd;
int best;

void floyd(int n){
	for (int k = 0; k < n; ++k){
		for (int i = 0; i < n; ++i){
			for (int j = 0; j < n; ++j){
				if (g[i][k] != -1 and g[k][j] != -1){
					int tmp = g[i][k] + g[k][j];
					if (g[i][j] == -1 or g[i][j] > tmp)
						g[i][j] = tmp;
				}
			}
		}
	}
	for (int i =0; i < n; ++i)
		g[i][i] = 0;
}

void checksum(){
	int i, tmp;
	for (i = tmp = 0; 2*i < odd; ++i){
		tmp += g[a[2*i]][a[2*i+1]];
	}
	if (best == -1 or best > tmp)
		best = tmp;
}

void perfectMatching(int x){
	int i, t;
	if (x == 2){
		checksum();
	}
	else{
		perfectMatching(x-2);
		for (i = x-3; i >= 0; --i){
			swap(a[i], a[x-2]);
			perfectMatching(x-2);
		}

		t = a[x-2];
		for (i = x-2; i >= 1; --i)
			a[i] = a[i-1];

		a[0] = t;
	}
}

int solve(int n){
	int i;
	floyd(n);
	for (odd = i =0; i < n; ++i){
		if (deg[i]&1)
			a[odd++] = i;
	}
	if (!odd)
		return sum;
	best = -1;
	perfectMatching(odd);
	return sum + best;
}

int main(){
	int i, u, v, c, n, m;

	while (1){
		cin >> n;
		if (n == 0)
			break;
		cin >> m;
		memset(g, -1, sizeof(g));
		memset(deg, 0, sizeof(deg));

		for (sum = i = 0; i < m; ++i){
			cin >> u >> v >> c;
			u--; v--;
			deg[u]++; deg[v]++;
			if (g[u][v] == -1 or g[u][v] > c)
				g[u][v] = c;
			if (g[v][u] == -1 or g[v][u] > c)
				g[v][u] = c;

			sum += c;
		}
		cout << solve(n) << endl;
	}

	return 0;
}
