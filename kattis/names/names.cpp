#include <bits/stdc++.h>
using namespace std;
#define SIZE 10000

int count_even(string s, int i){
  // cout << "i = " << i << endl;
  int j = i - 1;
  int cnt = 0;
  while (i < s.length()){
    if (s[i] != s[j]){
      s[i] = s[j];
      ++cnt;
    }
    j--;
    i++;
  }

  while (j >= 0){
    s += s[j];
    ++cnt;
    --j;
  }
  // cout << s << endl;

  return cnt;
}

int count_odd(string s, int i){
  // construct a palindrome centered at i
  int j = 1;
  int cnt = 0;
  while (i+j < s.length()){
    if (s[i+j] != s[i-j]){
      s[i+j] = s[i-j];
      ++cnt;
    }
    j++;
  }
  while (i-j >= 0){
    s += s[i-j];
    ++cnt;
    j++;
  }
  // cout << "i = " << i << endl;
  // cout << s << endl;
  return cnt;
}

int solve(string s){
  int n = s.length();
  int i = n/2;
  int ans = n;
  for (; i < n; ++i){
    ans = min(ans, count_odd(s, i));
    ans = min(ans, count_even(s, i));
  }
  return ans;
}

int main(){
  string s;
  cin >> s;
  cout << solve(s) << endl;
  return 0;
}