#include <iostream>
#include <set>
#include <algorithm>
#include <cctype>
using namespace std;

struct classcomp{
	bool operator()(const string& a, const string& b) const {
		return a < b;
	}
};

int main(){
	set<string, classcomp> words;
	string word;
	while (cin >> word){
		string _word = "";
		for (int i = 0; i < word.length(); ++i){
			if (word[i] >= 'a' and word[i] <= 'z'){
				_word.push_back(word[i]);
			}
			else if (word[i] >= 'A' and word[i] <= 'Z'){
				_word.push_back(tolower(word[i]));
			}
		}

		if (_word != "")words.insert(_word);
	}

	//sort(words.begin(), words.end());

	for (string w : words){
		cout << w << endl;
	}

	return 0;
}
