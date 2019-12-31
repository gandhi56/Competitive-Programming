#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

map<string, int> id;
bool ok[22][22];

bool all_good(vector<int> perm){
	for (int i = 0; i < perm.size() - 1; ++i){
		if (!ok[perm[i]][perm[i+1]])	return false;
	}
	return true;
}

void solve(vector<string> names){
	vector<int> perm;
	for (int i = 0; i < names.size(); ++i){
		perm.push_back(i);
	}

	do{

	if (all_good(perm)){
		for (int i = 0; i < perm.size(); ++i){
			cout << names[perm[i]] << " ";
		}
		cout << endl;
		return;
	}
	
	}	while (next_permutation(perm.begin(), perm.end()));

	cout << "You all need therapy." << endl;

}

int main(){


	int n;
	while (cin >> n){
		for (int i = 0; i < 22; ++i){
			for (int j = 0; j < 22; ++j){
				ok[i][j] = true;
			}
		}
		
		vector<string> names;
		for (int i = 0; i < n; ++i){
			string name;
			cin >> name;
			names.push_back(name);
		}

		sort(names.begin(), names.end());

		for (int i = 0; i < names.size(); ++i){
			id[names[i]] = i;
		}

		int m;
		cin >> m;

		while (m--){
			string a, b;
			cin >> a >> b;
			ok[ id[a] ][ id[b] ] = false;
			ok[ id[b] ][ id[a] ] = false;
		}

		solve(names);

	}

	return 0;
}
