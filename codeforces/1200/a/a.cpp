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


int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  int n;
  cin >> n;

  string s;
  cin >> s;

  bitset<10> r;
  int i = 0;
  int j = 9;
  for (auto c : s){
    if (c == 'L'){
      r[j] = true;
    }
    else if (c == 'R'){
      r[i] = true;
    }
    else{
      int idx = (int)(c - '0');
      r[9-idx] = false;
    }
    i = 0;
    j = 9;
    while (r[j])    j--;
    while (r[i])    i++;
  }
  cout << r << endl;

  return 0;
}
