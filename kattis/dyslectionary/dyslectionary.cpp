#include <iostream>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

int main(){
	int maxchar =0 ;
	string word;
	map<string, string> dict;
	while (getline(cin, word)){
		if (word == ""){
			map<string,string>::iterator it = dict.begin();
			while (it != dict.end()){
				for (int i = 0; i < maxchar - it->second.size(); ++i)	cout<<' ';

				cout << it->second << endl;
				it++;
			}
			cout << endl;
			dict.clear();
			maxchar = 0;
		}
		else{
			string rev = word;
			reverse(rev.begin(), rev.end());
			dict[rev] = word;
			maxchar = max(maxchar, (int)word.size());
		}
	}

	map<string,string>::iterator it = dict.begin();
	while (it != dict.end()){
		for (int i = 0; i < maxchar - it->second.size(); ++i)	cout << ' ';
		cout << it->second << endl;
		it++;
	}
	return 0;
}
