
#define MAXN  100010
#define K     16

#include <iostream>

using namespace std;
typedef long long ll;

string s;
ll st[MAXN][K];

ll sum(int l, int r){
  ll tot = 0;
  for (int j = K; j >= 0; j--){
    if ((1<<j) <= r - l + 1){
      tot += st[l][j];
      l += (1 << j);
    }
  }
  return tot;
}

int main(){
  int k;
  cin >> k;
  cin >> s;
  
  int n = s.length();
  
  // construct sparse table
  // - time complexity : O(nlogn)
  for (int i = 0; i < n; i++)
    st[i][0] = (s[i] == '1'? 1 : 0);

  for (int j = 1; j <= K; j++){
    for (int i = 0; i + (1<<j) <= n; i++)
      st[i][j] = st[i][j-1] + st[i + (1 << (j-1))][j-1];
  }

  bool done = false;
  double ans = -1;
  int f = -1, l = -1;
  for (int i = 0; i < n and !done; ++i){
    for (int len = k; i+len-1 < n and !done; ++len){
      double val = (double)sum(i, i+len-1) / (double)len;
      if (ans == -1 or val > ans){
        ans = val;
        f = i+1;
        l = len;
      }
      if (ans == 1) done = true;
    }
  }
  cout << f << ' ' << l << endl;
  return 0;
}
