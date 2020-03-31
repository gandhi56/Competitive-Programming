#define LIN cout << __LINE__ << endl;
#define INF 0x3f3f3f3f
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

inline bool ispal(string x){
  for (int i = 0; i < sz(x)/2+1; ++i)
    if (x[i] != x[sz(x) - i - 1])
      return false;
  return true;
}

inline string getrev(string x){
  string rev;
  for (int i = sz(x)-1; i >= 0; --i)
    rev.push_back(x[i]);
  return rev;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  int n, m;
  cin >> n >> m;

  map<string, int> s;
  while (n--){
    string x;
    cin >> x;
    if (s.count(x) == 0)
      s[x] = 0;
    s[x]++;
  }

  string l, c, r;
  for (auto& x : s){
    if (x.second == 0)  continue;
    bool pal = ispal(x.first);
    if (x.second == 1 and sz(x.first) > sz(c) and ispal(x.first)){
      c = x.first;
      x.second--;
    }
    else{
      if (pal){
        while (x.second >= 2){
          l = x.first + l;
          r = r + x.first;
          x.second -= 2;
        }
        if (x.second == 1 and sz(x.first) > sz(c)){
          c = x.first;
          x.second--;
        }
      }
      else{
        auto rx = getrev(x.first);
        auto it = s.find(rx);
        if (it == s.end())  continue;
        int cnt = min(it->second, x.second);
        while (x.second and it->second){
          l = x.first + l;
          r = r + it->first;
          x.second--;
          it->second--;
        }
      }
    }
  }

  cout << sz(l)+ sz(c) + sz(r) << endl;
  cout << l << c << r << endl;


  return 0;
}
