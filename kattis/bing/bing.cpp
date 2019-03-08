#include <iostream>
#include <map>

using namespace std;


struct Trie{
	map<char, Trie*> c;
	int count;

	Trie()	:	count(0)	{}
};

int process(char* word, Trie* node){
	
	++node->count;
	if (*word){
		if (node->c.find(*word) == node->c.end()){
			node->c[*word] = new Trie;
		}

		return process(word+1, node->c[*word]);
	}

	return node->count-1;
}

int main(){
	int n;
	char word[40];

	Trie* root = new Trie();
	cin >> n;
	while (n--){
		cin >> word;
		cout << process(word, root) << endl;
	}

	return 0;
}
