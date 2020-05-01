#define LIN cout << __LINE__ << endl;
#define INF 0x3f3f3f3f
#include <bits/stdc++.h>
using namespace std;

#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve(){
  string s;
  cin >> s;

  string a, b;
  string ra, rb;
  int i = 0;
  int j = sz(s)-1;
  while (i <= j){
    if (s[i] == s[j]){
      if (a.back() == s[j+1]){
        a += s[i];
        if (i != j)
          ra = s[j] + ra;
        i++;
        j--;
      }
      else{
        break;
      }
    }
    else{
      j--;
    }
  }
  a += ra;

  i = 0;
  j = sz(s)-1;
  while (i <= j){
    if (s[i] == s[j]){
      b += s[i];
      if (i != j)
        rb = s[j] + rb;
      i++;
      j--;
    }
    else{
      i++;
    }
  }
  b += rb;

  if (sz(a) > sz(b))
    cout << a << endl;
  else
  {
    cout << b << endl;
  }
  

}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);

  int t;
  cin >> t;

  while (t--)
    solve();

  return 0;
}
