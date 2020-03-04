
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

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  string mov;

  set<ii> pos;
  vector<int> dr, dc;
  dr.pb(0);
  dc.pb(0);
  int i = 0;
  int j = 0;
  while (cin >> mov){
    if (mov == "down")    i++;
    else if (mov == "up") i--;
    else if (mov == "right")  j++;
    else
      j--;
    dr.pb(i);
    dc.pb(j);
    pos.insert({i,j});    
  }

  int l, r, u, d;
  l = *min_element(dc.begin(), dc.end());
  r = *max_element(dc.begin(), dc.end());
  u = *min_element(dr.begin(), dr.end());
  d = *max_element(dr.begin(), dr.end());
  
  int numRows = d - u + 1;
  int cnt = r - l + 3;
  for (int i = 0; i < cnt; ++i) cout << '#';
  cout << endl;
  for (int i = u; i <= d; ++i){
    string row = "#";
    for (int j = l; j <= r; ++j){
      if (i == 0 and j == 0)  row += "S";
      else if (i == dr.back() and j == dc.back()) row += "E";
      else if (pos.find({i,j}) != pos.end())  row += "*";
      else
      {
        row += " ";
      }
    }
    row += "#";
    cout << row << endl;
  }
  for (int i = 0; i < cnt; ++i) cout << '#';
  cout << endl;

  return 0;
}