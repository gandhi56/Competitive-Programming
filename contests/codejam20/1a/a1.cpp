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

string reduce(string& s){
  string ss;
  int i = 0;
  while (i < sz(s)){
    if (s[i] == '*'){
      ss.push_back('*');
      i++;
      while (i < sz(s) and s[i] == '*')   i++;
    }
    else{
      ss.push_back(s[i]);
      i++;
    }
  }
  return ss;
}

string match(string a, string b){
  if (sz(b) < sz(a))    swap(a, b);
  
  a = "$" + a;
  b = "$" + b;
  //cout << "a = " << a << endl;
  //cout << "b = " << b << endl;

  string c;

  int i = sz(a)-1;
  int j = sz(b)-1;
  while (i >= 0 and j >= 0){
  
    if (a[i] == b[j]){
      if (a[i] == '$')  break;
      if (a[i] != '*'){
        c.push_back(a[i]);
      }
      i--;
      j--;
    }
    else{
      if (a[i] == '*'){
        while (b[j] != a[i-1] and b[j] != '*'){
          c.push_back(b[j]);
          j--;
        }
        i--;
      }
      else if (b[j] == '*'){
        while (a[i] != b[j-1] and a[i] != '*'){
          c.push_back(a[i]);
          i--;
        }
        j--;
      }
      else{
        return "*";
      }
    }

  }
  reverse(all(c));
  return c;

}

void solve(int tc){
  int n;
  cin >> n;

  vector<string> p;
  for (int i =0 ; i < n; ++i){
    string pat;
    cin >> pat;
    p.push_back(reduce(pat));
  }

  string m = match(p[0], p[1]);
  for (int i = 2; i < n; ++i)
    m = match(m, p[i]);

  cout << "Case #" << tc << ": " << m << endl;
}


int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  int t;
  cin >> t;
  for (int tc = 1; tc <= t; ++tc){
    solve(tc);
  }

  return 0;
}
