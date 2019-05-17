#include <iostream>
#include <algorithm>
using namespace std;

#define INF 29999

int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;

	while (t--){
		int ng, nm;
		cin >> ng >> nm;

		int g[ng];
		int m[nm];
		for (int i = 0; i < ng; ++i)	cin >> g[i];
		for (int i = 0; i < nm; ++i)	cin >> m[i];

		sort(g, g+ng);
		sort(m, m+nm);

		int i = 0;	// weakest g monster
		int j = 0;	// weakest m monster
		while (i < ng and j < nm){
			if (g[i] < m[j]){
				g[i] = INF;
				i++;
			}
			else if (g[i] >= m[j]){
				m[j] = INF;
				j++;
			}
		}
		if (i == ng){
			cout << "MechaGodzilla" << endl;
		}
		else{
			cout << "Godzilla" << endl;
		}

	}

	return 0;
}
