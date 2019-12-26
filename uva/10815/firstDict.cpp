#include <iostream>
#include <set>
using namespace std;

int main(){
	set<string> words;
	string word;
	while (cin >> word){
		string _word = "";
		for (int i = 0;i < word.size(); ++i){
			char c = tolower(word[i]);
			if (c >= 'a' and c <= 'z'){
				_word += c;
			}
			else if (_word != ""){
				words.insert(_word);
				_word = "";
			}
		}

		if (_word != "")	words.insert(_word);
	}

	for (auto it = words.begin(); it != words.end(); ++it){
		cout << *it << endl;
	}

	return 0;
}
