#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	int t;
	cin >> t;

	while (t--){
		int n;
		cin >> n;

		map<string,int> c;
		for (int i =0 ; i < n; ++i){
			string name;
			int val;
			cin >> name >> val;
			if (c.count(name)){
				c[name] += val;
			}
			else{
				c[name] = val;
			}
		}

		vector< pair<int,string> > v;
		for (auto k : c){
			v.push_back({-k.second, k.first});
		}

		sort(v.begin(), v.end());

		cout << v.size() << endl;
		for (auto k : v){
			cout << k.second << " " << -k.first << endl;
		}

	}

	return 0;
}
