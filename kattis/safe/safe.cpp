#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

typedef vector<int> vi;

vi play(vi g, int row, int col, int i){

	for (int r = 0; r < 3; ++r){
		for (int c = 0; c < 3; ++c){
			g[r*3+c] += 4;
		}
	}

	for (int i =0; i < 3; ++i){
		g[row*3+i]--;
	}
	for (int i =0; i < 3; ++i){
		g[i*3+col]--;
	}
	g[row*3+col]++;
	for (int r = 0; r < 3; ++r){
		for (int c = 0; c < 3; ++c){
			g[r*3+c] %= 4;
		}
	}
	return g;
}

void bfs(map<vi, int>& dist){
	queue<vi> q;

	vi end({0,0,0,0,0,0,0,0,0});
	dist[end] = 0;

	q.push(end);
	while (!q.empty()){
		vi curr = q.front();
		q.pop();

		for (int r = 0; r < 3; ++r){
			for (int c = 0; c < 3; ++c){
				vi next = play(curr, r, c, 1);
				if (dist.count(next) == 0){
					dist[next] = dist[curr] + 1;
					q.push(next);
				}
			}
		}

	}
}

int main(){
	vector<int> g;
	for (int i = 0; i < 9; ++i){
		int x;
		cin >> x;
		g.push_back(x);
	}

	map<vi, int> dist;
	bfs(dist);

	if (dist.count(g) == 0){
		cout << -1 << endl;
	}
	else{
		cout << dist[g] << endl;
	}

	return 0;
}
