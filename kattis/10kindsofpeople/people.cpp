#include <iostream>
#include <cstring>
#include <queue>
#include <cstdio>
using namespace std;
int r, c;

char g[1010][1010];
bool marked[1010][1010];
struct pos{
	int r, c;
	pos(){}
	pos(int rr, int cc)	:	r(rr), c(cc)	{}
};

void show(){
	for (int i = 1; i <= r; ++i){
		for (int j = 1; j <= c; ++j){
			cout << g[i][j];
		}
		cout << endl;
	}
}

void get_adj(pos curr, vector<pos>& next){
	char a = g[curr.r][curr.c];
	if (curr.r+1 <= r and g[curr.r+1][curr.c] == a){	
		next.push_back(pos(curr.r+1,curr.c));
	}
	if (curr.r-1 >= 1 and g[curr.r-1][curr.c] == a){	
		next.push_back(pos(curr.r-1,curr.c));
	}
	if (curr.c+1 <= c and g[curr.r][curr.c+1] == a){
		next.push_back(pos(curr.r,curr.c+1));
	}
	if (curr.c-1 >= 1 and g[curr.r][curr.c-1]){	
		next.push_back(pos(curr.r,curr.c-1));	
	}
}

void solve(pos s, pos t){

	if (g[s.r][s.c] != g[t.r][t.c]){
		cout << "neither" << endl;
		return;
	}

	for (int i = 1; i <= r; ++i){
		for (int j = 1; j <= c; ++j){
			marked[i][j] = false;
		}
	}
	
	queue<pos> q;
	marked[s.r][s.c] = true;
	q.push(s);
	while (!q.empty()){
		pos curr = q.front();
		q.pop();

		if (curr.r == t.r and curr.c == t.c){
			marked[t.r][t.c] = true;
			break;
		}

		vector<pos> next;
		get_adj(curr, next);
		for (pos adj : next){
			if (marked[adj.r][adj.c])					continue;
			if (g[curr.r][curr.c] != g[adj.r][adj.c])	continue;
			q.push(adj);
			marked[adj.r][adj.c] = true;
		}
	}

	if (marked[t.r][t.c]){
		if (g[t.r][t.c] == '0'){
			cout << "binary" << endl;
		}
		else{
			cout << "decimal" << endl;
		}
	}
	else{
		cout << "neither" << endl;
	}

}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> r >> c;

	for (int i = 1; i <= r; ++i){
		for (int j = 1; j <= c; ++j){
			cin >> g[i][j];
		}
	}

	int n;
	cin >> n;
	while (n--){
		pos s, t;
		cin >> s.r >> s.c >> t.r >> t.c;
		solve(s, t);
	}

	return 0;
}
