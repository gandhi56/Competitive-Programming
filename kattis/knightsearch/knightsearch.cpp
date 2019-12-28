#include <iostream>
#include <vector>
using namespace std;

typedef pair<int,int> ii;

char g[200][200];
const string targ = "ICPCASIASG";
int n;

inline int sq(int x){	return x*x;	}

bool ok(ii pos){	return 1<=pos.first<=n and 1<=pos.second<=n;	}

bool dfs(int a, int b, int i){
	if (i == targ.size())	return true;
	ii nextpos[] = { {a+2,b+1}, {a+2,b-1}, {a-2,b+1}, {a-2,b-1}, 
						{a+1,b+2}, {a+1,b-2}, {a-1,b+2}, {a-1,b-2} };
	for (int k = 0; k < 8; ++k){
		ii next = nextpos[k];
		if (!ok(next))	continue;
		if (g[next.first][next.second] == targ[i]){
			if (dfs(next.first, next.second, i+1))	return true;
		}
	}
	return false;
}

int main(){
	cin >> n;

	ii curr;
	vector<ii> startpos;
	for (int i = 1; i <= n; ++i){
		for (int j = 1; j <= n; ++j){
			cin >> g[i][j];
			if (g[i][j] == 'I')	startpos.push_back({i,j});
		}
	}

	bool solved = false;
	for (auto s : startpos){
		if (solved = dfs(s.first, s.second, 1))	break;
	}
	cout << (solved? "YES":"NO") << endl;

	return 0;
}
