#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int r, c;
char g[1010][1010];
int color[1010][1010];
int col;

struct pos{
	int r, c;
	pos(int rr, int cc)	:	r(rr), c(cc)	{}
};

void get_adj(pos s, vector<pos>& next){
	if (s.r+1 <= r and g[s.r+1][s.c] == g[s.r][s.c]){
		next.push_back(pos(s.r+1,s.c));
	}
	if (s.r-1 <= r and g[s.r-1][s.c] == g[s.r][s.c]){
		next.push_back(pos(s.r-1,s.c));
	}
	if (s.c+1 <= c and g[s.r][s.c+1] == g[s.r][s.c]){
		next.push_back(pos(s.r,s.c+1));
	}
	if (s.c-1 <= c and g[s.r][s.c-1] == g[s.r][s.c]){
		next.push_back(pos(s.r,s.c-1));
	}
}

void dfsLoop(int i, int j){
	color[i][j] = col;
	vector<pos> next;
	get_adj(pos(i,j), next);
	for (pos adj : next){
		if (color[adj.r][adj.c])	continue;
		dfsLoop(adj.r, adj.c);
	}
}

void dfs(){
	for (int i = 1; i <= r; ++i){
		for (int j = 1; j <= c; ++j){
			if (color[i][j] == 0){
				dfsLoop(i,j);
				col++;
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> r >> c;

	col = 1;
	for (int i = 1; i <= r; ++i){
		for (int j = 1; j <= c; ++j){
			cin >> g[i][j];
			color[i][j] = 0;
		}
	}

	dfs();

	int n;
	cin >> n;

	while (n--){
		pos s(0,0);
		pos t(0,0);
		cin >> s.r >> s.c >> t.r >> t.c;
		if (g[s.r][s.c] != g[t.r][t.c]){
			cout << "neither" << endl;
		}
		else{
			if (color[s.r][s.c] == color[t.r][t.c]){
				if (g[s.r][s.c] == '0'){
					cout << "binary" << endl;
				}
				else if (g[s.r][s.c] == '1'){
					cout << "decimal" << endl;
				}
			}
			else{
				cout << "neither" << endl;
			}
		}
	}

	return 0;
}
