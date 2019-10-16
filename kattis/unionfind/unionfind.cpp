#include <iostream>
using namespace std;

inline void initSet(int* par, int size){
	for (int i = 0; i < size; ++i){
		par[i] = i;
	}
}

int findSet(int* par,  int i){
	while (i != par[i]){
		i = par[i];
	}
	return i;
}

void unionSet(int* par, int i, int j){
	if (i == j)	return;
	i = findSet(par, i);
	j = findSet(par, j);
	if (i == j)	return;
	par[i] = j;
}

bool isSameSet(int* par, int i, int j){
	return findSet(par, i) == findSet(par, j);
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, q;
	cin >> n >> q;

	int par[n];
	initSet(par, n);

	while (q--){
		char c;
		int a, b;
		cin >> c >> a >> b;
		if (c == '?'){
			if (isSameSet(par, a, b)){
				cout << "yes" << endl;
			}
			else{
				cout << "no" << endl;
			}
		}
		else{
			unionSet(par, a, b);
		}
	}

	return 0;
}
