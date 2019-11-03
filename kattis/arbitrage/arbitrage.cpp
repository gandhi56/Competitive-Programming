#define MAXN 300
#include <bits/stdc++.h>
using namespace std;
int main(){
	double dist[MAXN][MAXN];
	int c;
	while (cin >> c and c){
		map<string,int> val;
		for (int i = 0; i < c; ++i){
			string curr;
			cin >> curr;
			val[curr] = i;
			for (int j = 0; j < c; ++j)
				dist[i][j] = 0.0;
			dist[i][i] = 1.0;
		}

		int r;
		cin >> r;
		for (int i = 0; i < r; ++i){
			string cur1, cur2;
			string tmp;
			int ind1, ind2;

			cin >> cur1 >> cur2;

			int i1 = val[cur1];
			int i2 = val[cur2];

			getline(cin, tmp, ':');
			stringstream ss(tmp);
			ss >> ind1;
			cin >> ind2;

			dist[i1][i2] = max(dist[i1][i2], (double)ind2 / (double)ind1);
		}

		// floyd warshall
		for (int k = 0; k < c; ++k){
			for (int i = 0; i < c; ++i){
				for (int j = 0; j < c; ++j){
					dist[i][j] = max(dist[i][j], dist[i][k] * dist[k][j]);
				}
			}
		}

		for (int i = 0; i < c; ++i){
			if (dist[i][i] > 1.0){
				cout << "Arbitrage" << endl;
				goto done;
			}
		}
		cout << "Ok" << endl;
		done:;
	}
	return 0;
}
