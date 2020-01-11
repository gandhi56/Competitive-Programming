#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

int solve(vi& a, int k){
  if (k<0)  return 0;
  vi l, r;
  for (auto& x : a){
    if (x&(1<<k)){
      r.push_back(x);
    }
    else{
      l.push_back(x);
    }
  }
  if (l.empty())  return solve(r, k-1);
  if (r.empty())  return solve(l, k-1);
  return min(solve(l, k-1), solve(r, k-1)) + (1<<k);
}

int main(){
  int n;
  cin >> n;
  vi a(n);
  for (int& i : a)  cin >> i;
  cout << solve(a, 30) << endl;
  return 0;
}
