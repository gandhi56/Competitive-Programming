#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 1e9

struct mov{
	int pos, jump, cost;

	mov(){}
	mov(int p, int j, int c)	:	pos(p), jump(j), cost(c)	{}
	
	bool operator<(const mov& rhs)	const 	{
		return cost > rhs.cost;
	}
};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	int entry[n];
	for (int i = 1; i <= n; ++i)	cin >> entry[i];

	int dist[n+1][n+1];
	for (int i = 0; i <= n; ++i){
		for (int j = 0; j <= n; ++j){
			dist[i][j] = INF;
		}
	}

	priority_queue< mov > pq;
	mov m;
	pq.push(mov(1, 0, 0));
	dist[1][0] = 0;

	while (!pq.empty()){
		m = pq.top();
		pq.pop();
		if (dist[m.pos][m.jump] != m.cost)	continue;
		if (m.pos == n)	break;
		int fpos = m.pos+m.jump+1;
		int bpos = m.pos-m.jump;
		if (fpos <= n){
			int newCost = m.cost + entry[fpos];
			if (newCost < dist[fpos][m.jump+1]){
				dist[fpos][m.jump+1] = m.cost + entry[fpos];
				pq.push(mov(fpos, m.jump+1, newCost));
			}
		}
		if (bpos > 0){
			int newCost = m.cost + entry[bpos];
			if (newCost < dist[bpos][m.jump]){
				dist[bpos][m.jump] = newCost;
				pq.push(mov(bpos, m.jump, newCost));
			}
		}
	}

	cout << m.cost << endl;

	return 0;
}
