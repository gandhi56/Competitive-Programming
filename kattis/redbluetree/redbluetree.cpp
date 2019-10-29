

#define MAXN 1001

#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;

vector<int> pset;
void initSet(int size)	{	pset.resize(size);	for (int i = 0; i < size; ++i)	pset[i] = i;	}
int findSet(int i)		{	return (i == pset[i] ? i : pset[i] = findSet(pset[i]));				}

bool unionSet(int i, int j){
	if ((i = findSet(i)) == (j = findSet(j)))	return false;
	pset[findSet(i)] = j;
	return true;
}

char color[MAXN][MAXN];

int main(){
	int n, m, k;
	cin >> n >> m >> k;

	initSet(n);
	vector<ii> tree1, tree2;
	vector<ii> edges;

	int b = 0;
	for (int i = 0; i < m; ++i){
		char c;
		int f, t;
		cin >> c >> f >> t;
		--f; --t;
		color[f][t] = color[t][f] = c;
		edges.push_back({f, t});
		b = (c == 'B' ? b+1 : b);
	}


	if (b < k){
		cout << 0 << endl;
		return 0;
	}

	b = 0;
	int r = 0;

	// add red edges, either get a forest or a tree
	for (auto e : edges){
		if ( color[e.first][e.second] == 'R' and unionSet(e.first, e.second)){
			tree1.push_back(e);
			r++;
			//cout << "adding " << e.first << "-" << e.second << endl;
		}
	}
	for (auto e : edges){
		if ( color[e.first][e.second] == 'B' and unionSet(e.first, e.second)){
			tree1.push_back(e);
			b++;
			//cout << "adding " << e.first << "-" << e.second << endl;
		}
	}

	if (tree1.size() < n-1 or b > k){	// tree cannot have more than n-1 edges, connectivity
		// no spanning tree exists or the tree requires too many blue edges
		cout << 0 << endl;
		return 0;
	}
	else if (tree1.size() == n-1 and b == k){	// already found a solution
		cout << 1 << endl;
		return 0;
	}

	//cout << "found T of size " << tree1.size() << endl;
	//cout << "r = " << r << endl;
	//cout << "b = " << b << endl;

	initSet(n);
	r = 0;
	b = 0;
	
	// add blue edges from tree1
	for (auto e : tree1){
		if (color[e.first][e.second] == 'B' and unionSet(e.first, e.second)){
			tree2.push_back(e);
			b++;
		//cout << e.first << " " << e.second << endl;
		}
	}

	// add remaining blue edges until k is reached
	for (auto e : edges){
		if (color[e.first][e.second] == 'B' and b < k and unionSet(e.first, e.second)){
			tree2.push_back(e);
			b++;
		//cout << e.first << " " << e.second << endl;
		}
	}

	// add red edges and hopefully tree2 is connected
	for (auto e : edges){
		if (color[e.first][e.second] == 'R' and unionSet(e.first, e.second)){
			tree2.push_back(e);
			r++;
		}
	}

	//cout << "size = " << tree2.size() << endl;
	cout << (b == k and tree2.size() == n-1? 1 : 0) << endl;

	return 0;
}
