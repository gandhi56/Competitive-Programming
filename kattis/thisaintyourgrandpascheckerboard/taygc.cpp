#define INF 0x3f3f3f3f
#define pb(x) push_back(x)
#define sz(x) (int)(x).size()
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll, ll> pii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vi> vii;
typedef vector<vector<ii>> viii;

bool check_rows(string s[], int n){
  for (int i = 0; i < n; ++i){
    int w = 0, b = 0;
    for (int j = 0; j < n; ++j){
      if (s[i][j] == 'W'){
        w++;
      }
      else{
        b++;
      }
    }
    if (w != b) return false;
  }

  for (int i = 0; i < n; ++i){
    for (int j = 0; j+2 < n; ++j){
      if (s[i][j] == s[i][j+1] and s[i][j+1] == s[i][j+2] and s[i][j] == s[i][j+2])
        return false;
    }
  }
  return true;
}

bool check_cols(string s[], int n){
  for (int i = 0; i < n; ++i){
    int w = 0, b = 0;
    for (int j = 0; j < n; ++j){
      if (s[j][i] == 'W'){
        w++;
      }
      else{
        b++;
      }
    }
    if (w != b) return false;
  }
  
  for (int i = 0; i < n; ++i){
    for (int j = 0; j+2 < n; ++j){
      if (s[j][i] == s[j+1][i] and s[j+1][i] == s[j+2][i] and s[j][i] == s[j+2][i])
        return false;
    }
  }
  return true;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  int n;
  cin >> n;

  string s[n];
  for (auto& x : s) cin >> x;

  cout << ( (check_rows(s, n) and check_cols(s, n))? 1 : 0) << endl;
  
  return 0;
}
