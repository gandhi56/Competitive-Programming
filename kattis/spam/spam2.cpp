
#define MAXN  100010
#include <iostream>

using namespace std;
typedef long long ll;

string s;
int n, t[4*MAXN];

void build(int v, int tl, int tr){
  if (tl == tr){
    t[v] = (s[tl] == 1? 1 : 0);
    return;
  }
  int tm = (tl + tr) / 2;
  build(v*2, tl, tm);
  build(v*2+1, tm+1, tr);
  t[v] = t[v*2] + t[v*2+1];
}

int sum(int v, int tl, int tr, int l, int r){
  if (l > r)  return 0;
  if (l == tl and r == tr)  return t[v];
  int tm = (tl + tr) / 2;
  return sum(v*2, tl, tm, l, min(r, tm)) + sum(v*2+1, tm+1, tr, max(l, tm+1), r);
}

int main(){
  int k;
  cin >> k;
  cin >> s;
  
  n = s.length();

  build();

  return 0;
}
