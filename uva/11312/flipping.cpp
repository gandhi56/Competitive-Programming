#include <iostream>
#include <queue>
#include <bitset>
using namespace std;

int n, l, r, t;

void solve(){
	bitset<10000100> visited;
	visited.reset();
	visited.set(1);
	queue<int> q;
	int minSteps = 0;
	q.push(1);
	while (!q.empty()){
		int u = q.front();
		q.pop();
		if (u == t)	break;
		if (u-l >= 2 and !visited[u-l]){
			q.push(u-l);
			visited.set(u-l);
		}
		if (u+r <= n and !visited[u+r]){
			q.push(u+r);
			visited.set(u+r);
		}
		minSteps++;
	}

	if (visited[t]){
		cout << minSteps << endl;
	}
	else{
		cout << "uh-oh!" << endl;
	}
}

int gcdExtended(int a, int b, int& x, int& y){
	if (a == 0){
		x = 0;
		y = 1;
		return b;
	}

	int x1, y1;
	int gcd = gcdExtended(b%a, a, x1, y1);
	x = y1 - (b/a) * x1;
	y = x1;

	return gcd;
}

int main(){
	int c;
	cin >> c;

	while (c--){
		cin >> n >> l >> r >> t;
		//solve();
		int x, y;
		cout << gcdExtended() << endl;
	}
	return 0;
}

