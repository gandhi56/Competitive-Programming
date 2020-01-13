#define INF 0x3f3f3f3f
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll, ll> pii;
typedef vector< vector<int> > vii;

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  string s;
  cin >> s;
  int cnt = 0;
  for (int i = 0; i < s.length(); ++i){
    if (s[i] != 'Q')  continue;
    for (int j = i+1; j < s.length(); ++j){
      if (s[j] != 'A')  continue;
      for (int k = j+1; k < s.length(); ++k){
        if (s[k] != 'Q')  continue;
        cnt++;
      }
    }
  }
  cout << cnt << endl;
  return 0;
}
