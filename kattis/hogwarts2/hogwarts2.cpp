#define FOO
#include <bits/stdc++.h>
using namespace std;

int n;
typedef pair<int,int> ii;
typedef vector< vector< int > > graph;

void print_graph(graph& g){
	for (int i = 0; i < g.size(); ++i){
		cout << i << " -> ";
		for (auto v : g[i]){
			cout << v << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int main(){
	cin >> n;

	graph g(n);
	graph h(n);

	// senior students graph
	for (int i = 0; i < n; ++i){
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		--a; --b; --c; --d;
		if (a >= 0)	g[i].push_back(a);
		if (b >= 0)	g[i].push_back(b);
		if (c >= 0)	g[i].push_back(c);
		if (d >= 0)	g[i].push_back(d);
	}

	for (int i = 0; i < n; ++i){
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		--a; --b; --c; --d;
		if (a >= 0)	h[i].push_back(a);
		if (b >= 0)	h[i].push_back(b);
		if (c >= 0)	h[i].push_back(c);
		if (d >= 0)	h[i].push_back(d);
	}

	print_graph(g);
	print_graph(h);

	int distg[n];
	int disth[n];
	for (int i = 0; i < n; ++i){
		distg[i] = -1;
		disth[i] = -1;
	}

	queue<ii> q;
	q.push({0,0});

	distg[0] = 0;
	disth[0] = 0;

	while (!q.empty()){
		ii curr = q.front(); q.pop();
		#ifdef FOO
			cout << "curr = (" << curr.first << ", " << curr.second << ")" << endl;
		#endif
		if (curr.first == n-1 and curr.second != n-1){
			cout << "No" << endl;
			return 0;
		}

		/*
		for (auto& next : g[curr.first]){
			if (dist[{next, curr.second}] >= 0)	continue;
			dist[{next,curr.second}] = currdist + 1;
			q.push({next, curr.second});
		}
		for (auto& next : h[curr.second]){
			if (dist[{curr.first, next}] >= 0)	continue;
			dist[{curr.first, next}] = currdist+1;
			q.push({curr.first, next});
		}
		*/

		for (auto& next1 : g[curr.first]){
			for (auto& next2 : h[curr.second]){
				if (distg[next1] >= 0 or disth[next2] >= 0)	continue;
				distg[next1] = distg[curr.first] + 1;
				disth[next2] = disth[curr.second] + 1;
				q.push({next1,next2});
			}
		}
	}

	cout << "distg[n-1] = " << distg[n-1] << endl;
	cout << "disth[n-1] = " << disth[n-1] << endl;

	if (distg[n-1] == disth[n-1]){
		cout << "Yes" << endl;
	}
	else{
		cout << "No" << endl;
	}

	return 0;
}
