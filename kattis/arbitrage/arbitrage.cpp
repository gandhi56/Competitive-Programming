#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

typedef pair<int,int> ii;

inline bool isbad(ii a){
	return a.first == 0 or a.second == 0;
}

void print(ii r){
	cout << r.first << "/" << r.second << endl;
}

int main(){
	while (1){
		int c;
		cin >> c;	// number of currencies

		if (c == 0)
			break;

		map<string, int> currIndex;
		for (int i = 0; i < c; ++i){
			string curr;
			cin >> curr;
			currIndex.insert({curr, i});
		}
		ii r[c][c];
		for (int i =0; i < c; ++i){
			for (int j = 0; j < c; ++j){
				r[i][j] = {0,0};
			}
		}

		int m;
		cin >> m;
		while (m--){
			// input rates for every pair
			string curr1, curr2;
			cin >> curr1 >> curr2;

			int c1, c2;
			char _;
			cin >> c1 >> _ >> c2;

			r[currIndex[curr1]][currIndex[curr2]] = {c1/__gcd(c1,c2), c2/__gcd(c1,c2)};

		}

		#ifdef debug
		for (int i = 0; i < c; ++i){
			for (int j = 0; j < c; ++j){
				cout << "(" << r[i][j].first << "," << r[i][j].second << ") ";
			}
			cout << endl;
		}
		#endif

		string res = "Ok";
		for (int i = 0; i < c and res == "Ok"; ++i){
			for (int j = 0; j < c and res == "Ok"; ++j){
				if (i == j or isbad(r[j][i]) or isbad(r[i][j]))	continue;
				double rate1 = (double)r[i][j].first / (double)r[i][j].second;
				double rate2 = (double)r[j][i].first / (double)r[j][i].second;
				if (rate1 != 1/rate2){
					res = "Arbitrage";
				}
			}
		}

		for (int k = 0; k < c and res == "Ok"; ++k){
			for (int i =0 ; i < c and res == "Ok"; ++i){
				for (int j = 0; j < c and res == "Ok"; ++j){
					if (i == j or j == k or i == k or isbad(r[i][j]) or isbad(r[i][k]) or isbad(r[k][j]))	continue;
					int a = r[i][k].first;
					int c = r[i][k].second;
					int b = r[k][j].first;
					int d = r[k][j].second;
					int num = a*b;
					int den = c*d;
					double rate1 = r[i][j].first / r[i][j].second;
					double rate2 = num / den;
					if (rate1 < rate2){
						//print(r[i][j]);
						//print(r[i][k]);
						//print(r[k][j]);
						//cout << "val2 ";
						//print(val2);
						res = "Arbitrage";
					}
				}
			}
		}

		cout << res << endl;

	}

	return 0;
}
