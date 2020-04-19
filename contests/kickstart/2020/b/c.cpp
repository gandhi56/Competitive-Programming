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

const int STEP = 1000000000;

struct pos{
  int r, c;
};

map<int,int> mat;

void next(pos& p, char c){
  if (c == 'N'){
    p.r--;
  }
  else if (c == 'S'){
    p.r++;
  }
  else if (c == 'W'){
    p.c--;
  }
  else if (c == 'E'){
    p.c++;
  }
}

void fix(int& x){
  if (x < 0){
    x += STEP;
  }
  x %= STEP;
}

void simple(pos& p, int k, string s){
  while (k--){
    for (char c : s)
      next(p, c);
  }
}

void fog(pos& p, string s, int i){
  // s[i] is the rep#
  int k = s[i] - '0';
  int j = i+2;
}

void solve(int tc){
  string s;
  cin >> s;

  stack<int> stk;
  mat.clear();
  for (int i = 0; i < sz(s); ++i){
    if (s[i] == '('){
      mat[i] = -1;
      stk.push(i);
    }
    else if (s[i] == ')'){
      mat[stk.top()] = i;
      stk.pop();
    }
  }

  for (auto it = mat.rbegin(); it != mat.rend(); ++it){
    int i = it->first;
    int j = it->second;

  }

  /*
  pos p{0,0};
  for (int i = 0; i < sz(s);){
    if (s[i] >= '2' and s[i] <= '9'){
      
    }
    else{
      next(p, s[i]);
      i++;
    }

    // fix p
    fix(p.r);
    fix(p.c);
    cout << p.c+1 << ' ' << p.r+1 << endl;
  }
  */
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  int t;
  cin >> t;
  for (int tc = 1; tc <= t; ++tc)
    solve(tc);

  return 0;
}
