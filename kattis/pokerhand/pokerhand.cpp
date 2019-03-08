#include <iostream>
#include <map>
using namespace std;

int main(){
	map<char, int> val;
	string s;
	while (cin >> s){
		val[s[0]]++;
	}

	int best = 0;
	for (auto i : val){
		best = max(best, i.second);
	}
	cout << best << endl;

	return 0;
}
