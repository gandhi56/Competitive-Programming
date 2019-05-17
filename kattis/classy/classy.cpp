#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

string getRank(string name, string rank){
	string r;
	for (int i = 0; i < rank.length(); ++i){
		if (rank[i] == 'u'){
			r += 'a';
		}
		if (rank[i] == 'm'){
			r += 'b';
		}
		if (rank[i] == 'o'){
			r += 'c';
		}
	}


	int len = r.length();
	for (int j = 0; j < len/2; ++j){
		swap(r[j], r[len-j-1]);
	}

	while (len < 10){
		len++;
		r += 'b';
	}

	r += " " + name;
	r.pop_back();

	return r;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;

	while (t--){
		int n;
		cin >> n;

		vector<string> names;
		while (n--){
			string name, rank,gg;
			cin >> name >> rank >> gg;
			rank = getRank(name, rank);
			names.push_back(rank);
		}
		sort(names.begin(), names.end());
		for (auto name : names){
			int i = 0;
			while (name[i] != ' ')	i++;
			i++;
			for (; i < name.length(); ++i){
				cout << name[i];
			}
			cout << endl;
		}
		cout << "==============================" << endl;

	}
	return 0;
}
