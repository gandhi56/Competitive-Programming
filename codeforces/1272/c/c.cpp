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

  int n, k;
  cin >> n >> k;

  string s;
  cin >> s;

  set<char> c;
  for (int i = 0; i < k; ++i){
    char cc;
    cin >> cc;
    c.insert(cc);
  }

  ull ans =0 ;
  int i =0 ;
  while (i < n){
    if (c.find(s[i]) == c.end()){
      i++;
      continue;
    }
    int j = i + 1;
    while (j < n){
      if (c.find(s[j]) != c.end()){
        j++;
      }
      else{
        break;
      }
    }

    // cout << i << ':' << j << endl;

    ull len = j-i;
    ans += len*(len+1)/2;
    i = j+1;
  }

  cout << ans << endl;

  return 0;
}












