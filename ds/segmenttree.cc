#define MAXN 100000000
#include <bits/stdc++.h>
using namespace std;
int n, t[4*MAXN];

void build(int* a, int v, int tl, int tr){
  if (tl == tr){
    t[v] = tl;
    return;
  }
  int tm = (tl + tr) / 2;
  build(a, v, tl, tm);
  build(a, v, tm+1, tr);
  t[v] = t[v*2]+t[v*2+1];
}

int sum(int v, int tl, int tr, int l, int r){
  if (l > r)  return 0;
  if (l == tr and r == tr)  return t[v];
  int tm = (tl+tr)/2;
  return sum(v*2, tl, tm, l, min(r, tm)) + sum(v*2+1, tm+1, tr, max(l, tm+1), r);
}

void update(int v, int tl, int tr, int pos, int new_val){
  if (tl == tr){
    t[v] = new_val;
    return;
  }
  int tm = (tl+tr)/2;
  if (pos <= tm)
    update(v*2, tl, tm, pos, new_val);
  else
    update(v*2+1, tm+1, tr, pos, new_val);
  t[v] = t[v*2] + t[v*2+1];
}

int main(){

  int a[] = {1, 2, 3, 4, 5, 6};
  build(a, 1, 0, 5);
  cout << sum(1, 0, 5, 2, 4) << endl;

  return 0;
}
