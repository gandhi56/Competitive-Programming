#include <bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	vector< queue<string> > owner(n);
	unordered_map<string,bool> alloc;

	for (int i = 0; i < n; ++i){
		// input owner's preference list
		int q;
		cin >> q;
		while (q--){
			string player;
			cin >> player;
			owner[i].push(player);
			if (alloc.find(player) == alloc.end())
				alloc[player] = false;
		}
	}

	int p;
	cin>> p;	// number of players in the draft
	queue<string> rank;
	for (int i = 0; i < p; ++i){
		string player;
		cin >> player;
		rank.push(player);
		if (alloc.find(player) == alloc.end())
			alloc[player] = false;
	}

	vector< vector<string> > team(n);
	int idx = 0;
	int cnt = n*k;
	while (cnt--){

		// select from preference list
		while (!owner[idx].empty()){
			string player = owner[idx].front();
			owner[idx].pop();
			if (alloc[player])	continue;
			alloc[player] = true;
			team[idx].push_back(player);
			goto loop;
		}

		// select from previous year's rankings
		while (!rank.empty()){
			string player = rank.front();
			rank.pop();
			if (alloc[player])	continue;
			alloc[player] = true;
			team[idx].push_back(player);
			goto loop;
		}

		loop:;
		idx = (idx + 1) % n;
	}

	for (int i =0 ; i < n; ++i){
		for (auto& player : team[i]){
			cout << player << ' ';
		}
		cout << endl;
	}

	return 0;
}
