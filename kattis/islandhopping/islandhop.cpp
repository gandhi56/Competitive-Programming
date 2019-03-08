#include <bits/stdc++.h>

using namespace std;

#define sqr(x) x*x

struct freckle{
	double x, y;
};

typedef pair<double, double> pdd;
typedef pair<freckle, freckle> ff;
typedef pair<double, int> pdi;

double dist(freckle a, freckle b){
	return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

void prim(freckle frecks[], int n){

	bool marked[n];
	memset(marked, false, sizeof(marked));

	double cost = 0.0;
	priority_queue< pdi, vector<pdi>, greater<pdi> > pq;
	pq.push(make_pair(0.0, 0));
	while (!pq.empty()){
		pdi edge = pq.top();
		int u = edge.second;
		double edgeCost = edge.first;
		
		pq.pop();
		
		if (marked[u])	continue;

		cost += edgeCost;
		

		marked[u] = true;

		for (int v = 0; v < n; ++v){
			if (!marked[v]){
				double w = dist(frecks[u], frecks[v]);
				pq.push(make_pair(w, v));

				//cout << "pushing " << v << " at " << w << endl;

			}
		}

	}

	cout << fixed << setprecision(3);
	cout << (double)cost << endl;

}

int main(){
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;

		freckle frecks[n];
		for (int i = 0; i < n; ++i){
			cin >> frecks[i].x >> frecks[i].y;
		}

		prim(frecks, n);
		
	}

	return 0;
}

