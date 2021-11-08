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
  for (int x = 0; x < 32; ++x){
    mem['p'] = (x>>0)&1;
    mem['q'] = (x>>1)&1;
    mem['r'] = (x>>2)&1;
    mem['s'] = (x>>3)&1;
    mem['t'] = (x>>4)&1;
    cerr << mem['p'] << mem['q'] << mem['r'] << mem['s'] << mem['t'] << endl;
    auto res = eval(tree, mem);
    cerr << "res = " << res << endl;
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