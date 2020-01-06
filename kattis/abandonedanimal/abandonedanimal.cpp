#include <bits/stdc++.h>
using namespace std;
typedef vector< set<string> > vvs;

bool solve(vvs& inv, vector<string>& p, int idx){
	if (idx == p.size()){
		return true;
	}

	// in store 'idx'
	for (int i = 0; i < inv.size(); ++i){
		if (inv[i].find(p[idx]) == inv[i].end())	continue;
		
		// go to the next store and search for the next item
		if (solve(inv, p, idx+1))	return true;
	}
	return false;
}

int main(){
	int n, k;
	cin >> n >> k;

	vvs inv(n);
	while (k--){
		int x;
		string s;
		cin >> x >> s;
		inv[x].insert(s);
	}

	int m;
	cin >> m;
	vector<string> p;
	while (m--){
		string s;
		cin >> s;
		p.push_back(s);
	}

	vector<int> fpath, bpath;
	for (auto& itm : p){
		bool found = false;
		int i = 0;
		if (!fpath.empty())	i = fpath.back();
		for (; i < inv.size(); ++i){
			if (inv[i].find(itm) != inv[i].end()){
				fpath.push_back(i);
				found = true;
				break;
			}
		}
		if (!found){
			cout << "impossible" << endl;
			return 0;
		}
	}

	reverse(p.begin(), p.end());
	
	for (auto& itm : p){
		int i = inv.size()-1;
		if (!bpath.empty())	i = bpath.back();
		for (; i < inv.size(); --i){
			if (inv[i].find(itm) != inv[i].end()){
				bpath.push_back(i);
				break;
			}
		}
	}

	reverse(bpath.begin(), bpath.end());
	if (fpath == bpath){
		cout << "unique" << endl;
	}
	else{
		cout << "ambiguous" << endl;
	}
	
	return 0;
}
