#include <bits/stdc++.h>
using namespace std;

unsigned int brute_force(unsigned int a, unsigned int b){
  unsigned int ans = a;
  for (unsigned int x = a+1; x <= b; ++x)
    ans &= x;
  return ans;
}

unsigned int better_soln(unsigned int a, unsigned int b){
  unsigned int diff = b - a;
  while (__builtin_popcount(diff+1) != 1) diff++;
  unsigned int ans = a&b;
  for (int k = 0; k < __builtin_popcount(diff); ++k)
    ans >>= 1;
  for (int k = 0; k < __builtin_popcount(diff); ++k)
    ans <<= 1;
  return ans;
}

int main(){
  int n;
  cin >> n;
  while (n--){
    unsigned int a, b;
    cin >> a >> b;
    //cout << brute_force(a, b) << endl;
    cout << better_soln(a, b) << endl;
  }
  return 0;
}
