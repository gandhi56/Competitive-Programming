#include <iostream>
using namespace std;

int main(){
	int n;
	while (cin >> n){
		if (n == -1)	break;

		int dist = 0;
		int tmp = 0;
		for (int i = 0; i < n; ++i){
			int u, v;
			cin >> u >> v;
			dist += u*(v-tmp);
			tmp = v;
		}
		cout << dist << " miles" << endl;
	}

	return 0;
}
