#include <bits/stdc++.h>
using namespace std;

struct Trie{
  map<char, Trie*> c;
  bool isEnd;
  Trie() {
      isEnd = false;
  }
};

void addString(string s, Trie* node){
  Trie* tmp = node;
  for (int i = 0; i < s.length(); ++i){
    if (tmp->c.find(s[i]) == tmp->c.end())
      tmp->c[s[i]] = new Trie();
    tmp = tmp->c[s[i]];
  }
  tmp->isEnd = true;
}

string lcp(Trie* node){
  string ans = "";
  while (node and node->c.size() == 1 and !node->isEnd){
    char ch = node->c.begin()->first;
    ans.push_back(ch);
    node = node->c[ch];
  }
  return ans;
}

int main(){
	
	Trie* root = new Trie();
	addString("flower", root);
	addString("flow", root);
	addString("flight", root);

	cout << lcp(root) << endl;

	return 0;
}
