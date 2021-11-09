#include <bits/stdc++.h>

using namespace std;

struct Node{
  Node* left;
  Node* right;
  char value;
  Node(){
    left = nullptr;
    right = nullptr;
  }
  Node(char v){
    left = nullptr;
    right = nullptr;
    value = v;
  }
  bool isOp(){
    return (value == 'K' or value == 'A' or 
        value == 'N' or value == 'C' or 
        value == 'E');
  }
};

bool isLeaf(char c){
  return (c == 'p' or c == 'q' or c == 'r' or
    c == 's' or c == 't');
}

Node* constructTree(string s, int idx){
  Node* node = new Node(s[idx]);
  if (isLeaf(s[idx])){
    return node;
  }

  node->left = constructTree(s, idx+1);
  if (s[idx] != 'N')
    node->right = constructTree(s, idx+2);
  return node;
}

unsigned int eval(Node* t, map<char, unsigned int> mem){
  if (isLeaf(t->value)){
    cerr << "value of " << t->value << " is " << mem[t->value] << endl;
    return mem[t->value];
  }
  
  unsigned int left = eval(t->left, mem);
  unsigned int right;
  if (t->value != 'N')
    right = eval(t->right, mem);

  if (t->value == 'K') return left & right;
  if (t->value == 'A') return left | right;
  if (t->value == 'N') return left ^ 1;
  if (t->value == 'C') return (left & right) | (~left);
  if (t->value == 'E') return ~(left ^ right);
  return true;
}

bool isTaut(string s){
  Node* tree = constructTree(s, 0);
  map<char, unsigned int> mem;
  vector<char> vars;
  for (auto c : s){

    if (isLeaf(c)){
      mem[c] = 0;
      vars.push_back(c);
    }
  }

  auto mn = 1<<(mem.size());

  for (int x = 0; x < mn; ++x){
    // (x>>0)&1
    // (x>>1)&1
    // ...
    // (x>>(mem.size()-1))&1

    for (int i = 0; i < mem.size(); ++i)
      mem[vars[i]] = (x>>i)&1;

    auto res = eval(tree, mem);
    if (eval(tree, mem) == 0)
      return false;
  }
  return true;
}

int main(){
  string s;
  while (cin >> s && s != "0"){
    cout << (isTaut(s) ? "tautology" : "not") << endl;
  }
  return 0;
}
