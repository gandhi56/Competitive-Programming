#include <iostream>
#include <set>
using namespace std;

int main(){
	string s;
	cin >> s;

	int count =0;
	for (int i = 0; i < s.length(); ++i){
		set<char> seen;
		seen.insert(s[i]);
		for (int j = 1; i+j < s.length(); ++j){
			if (s[i] == s[i+j]){
				// not allowed to see the first character twice
				break;
			}
			else{
				if (seen.find(s[i+j]) == seen.end()){
					seen.insert(s[i+j]);
					count++;
				}
			}
		}
	}

	cout << count << endl;

	return 0;
}
