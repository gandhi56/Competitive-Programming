#include <iostream>
using namespace std;

int main(){
	int n, m;
	while (cin >> n >> m and n and m){
		int s[n], e[n];
		for (int i =0 ; i < n; ++i){
			int t;
			cin >> t >> t >> s[i] >> e[i];
			e[i] = s[i] + e[i] - 1;
		}

		while (m--){
			int a, b;
			cin >> a >> b;
			int count = 0;
			for (int i =0 ; i < n; ++i){
				if (a+b-1 >= s[i] and a <= e[i])	count++;
			}
			cout << count << endl;
		}
	}

	return 0;
}
