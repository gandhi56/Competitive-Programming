#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;


struct pos{
	int x, y;
	pos(int xx, int yy)	:	x(xx), y(yy)	{}
	pos()	:	x(0), y(0)	{}
};

typedef unordered_map<pos, vector<pos> > graph;
int main(){
	int n;
	cin >> n;

	while (n--){
		int s;
		cin >> s;

		graph g;
		pos curr(0,0);
		for (int i = 0; i < s; ++i){
			char dir;
			cin >> dir;
			if (dir == 'S'){
				g[curr].push_back(pos(0,-1));
			}
		}
	}

	return 0;
}
