#include <iostream>
#include <cstdio>
using namespace std;

typedef pair<int,int> ii;

int par[1000000];
int rk[1000000];

void initSet(int size){
	for (int i = 0; i < size; ++i){
		par[i] = i;
		rk[i] = 1;
	}
}

int findSet(int i){
	while (i != par[i]){
		i = par[i];
	}
	return i;
}

void unionSet(int i, int j){
	i = findSet(i);
	j = findSet(j);
	if (i == j)	return;
	if (rk[i] < rk[j]){
		par[i] = j;
		rk[j] += rk[i];
	}
	else{
		par[j] = i;
		rk[i] += rk[j];
	}
}

bool isSameSet(int i, int j){
	return findSet(i) == findSet(j);
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, q;
	cin >> n >> q;

	initSet(n);

	while (q--){
		char c;
		int a, b;
		cin >> c >> a >> b;
		if (c == '?'){
			if (isSameSet(a, b)){
				cout << "yes" << endl;
			}
			else{
				cout << "no" << endl;
			}
		}
		else{
			unionSet(a, b);
		}
	}

	return 0;
}
