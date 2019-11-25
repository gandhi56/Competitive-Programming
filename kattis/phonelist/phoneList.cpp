/*
Given a list of phone numbers, determine is a phone number is
a prefix of another.
*/

#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int t;
	cin >> t;

	while (t--){
		int n;
		cin >> n;

		string words[n];
		for (int i = 0; i < n; ++i)	cin >> words[i];

		sort(words, words+n);

		bool ok = true;
		for (int i =0 ; i < n-1; ++i){
			if (words[i].length() <= words[i+1].length()){
				string pref = words[i+1].substr(0, words[i].length());
				if (pref == words[i]){
					ok = false;
					break;
				}
			}
		}

		cout << (ok? "YES" : "NO") << endl;

	}
	return 0;
}
