#include <iostream>
#include <set>
using namespace std;

int main(){
	string s;
	cin >> s;

	int count = 0;
	for (int i = 0; i < s.length(); ++i){

		set<char> seen;

		int k = 1;
		char first = s[i];
		seen.insert(s[i]);
		while (i+k < s.length()){
			if (k == 1 and s[i] == s[i+1]){
				k++;
				continue;
			}
			if (seen.find(s[i+k]) == seen.end()){
				seen.insert(s[i+k]);
				count++;

				for (int j = i; j <= i+k; ++j){
					cout << s[j];
				}
				cout << endl;
			}
			k++;
		}
	}

	cout << count << endl;

	return 0;
}
