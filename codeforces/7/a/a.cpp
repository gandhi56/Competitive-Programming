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

string s[8];
int countRow(int i){
  int cnt = 0;
  for (int j =0 ; j < 8; ++j){
    cnt += (s[i][j] == 'B');
  }
  return cnt;
}

int countCol(int i){
  int cnt = 0;
  for (int j =0 ; j < 8; ++j){
    cnt += (s[j][i] == 'B');
  }
  return cnt;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  for (int i =0 ; i < 8; ++i)
    cin >> s[i];

  int a = 0;
  int b =0;
  for (int i =0 ; i < 8; ++i){
    if (countRow(i) == 8)
      a++;
    if (countCol(i) == 8)
      b++;
  }

  if (a == 8 and b == 8){
    cout << 8 << endl;
  }
  else{
    cout << a+b << endl;
  }

  return 0;
}
