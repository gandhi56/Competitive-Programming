#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct pos{
	int l, r, c;
	pos(){}
	pos(int ll, int rr, int cc)	:	l(ll), r(rr), c(cc){}
	bool operator==(const pos& p){
		return l == p.l and r == p.r and c == p.c;
	}
	void print(){
		cout << "(" << l << "," << r << "," << c << ")" << endl;
	}
};

int l, r, c;
char grid[40][40][40];

void bfs(pos s, pos t){
	int dist[40][40][40];
	for (int i = 0; i < l; ++i){
		for (int j = 0; j < r; ++j){
			for (int k = 0; k < c; ++k){
				dist[i][j][k] = -1;
			}
		}
	}
	queue< pos > q;
	q.push(s);
	dist[s.l][s.r][s.c] = 0;
	int currdist = 0;
	while (!q.empty()){
		pos u = q.front();
		q.pop();
		if (u == t)	break;
		currdist = dist[u.l][u.r][u.c];
		for (int k : {1, -1}){
			if (dist[u.l+k][u.r][u.c] == -1 and grid[u.l+k][u.r][u.c] != '#'){
				q.push(pos(u.l+k, u.r, u.c));
				dist[u.l+k][u.r][u.c] = currdist + 1;
			}
			if (dist[u.l][u.r+k][u.c] == -1 and grid[u.l][u.r+k][u.c] != '#'){
				q.push(pos(u.l, u.r+k, u.c));
				dist[u.l][u.r+k][u.c] = currdist + 1;
			}
			if (dist[u.l][u.r][u.c+k] == -1 and grid[u.l][u.r][u.c+k] != '#'){
				q.push(pos(u.l, u.r, u.c+k));
				dist[u.l][u.r][u.c+k] = currdist + 1;
			}
		}
	}

	if (dist[t.l][t.r][t.c] == -1){
		cout << "Trapped!" << endl;
	}
	else{
		cout << "Escaped in " << dist[t.l][t.r][t.c];
		cout << " minute(s)." << endl;
	}

}

void print(){
	for (int i = 0; i < l; ++i){
		for (int j = 0; j < r; ++j){
			for (int k = 0; k < c; ++k){
				cout << grid[i][j][k] << " ";
			}
			cout << endl;
		}
		cout << endl << endl;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	while (cin >> l >> r >> c){
		if (l == 0 and r == 0 and c == 0)	break;
		pos start;
		pos target;
		
		for (int i = 0; i < l; ++i){
			for (int j = 0; j < r; ++j){
				for (int k = 0; k < c; ++k){
					char c;
					while (cin >> c){
						if (c == '#' or c == '.' or c == 'S' or c == 'E'){
								grid[i][j][k] = c;
								break;
						}
					}
				}
			}
		}

		for (int i =0 ; i < l; ++i){
			for (int j = 0; j < r; ++j){
				for (int k =0 ; k < c; ++k){
					if (grid[i][j][k] == 'S'){
						start.l = i;
						start.r = j;
						start.c = k;
					}
					else if (grid[i][j][k] == 'E'){
						target.l = i;
						target.r = j;
						target.c = k;
					}
				}
			}
		}

		bfs(start, target);

	}
	return 0;
}
