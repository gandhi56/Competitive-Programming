#define INF 0x3f3f3f3f
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll, ll> pii;
typedef vector< vector<int> > vii;

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--){
    int n;
    cin >> n;
    string s1, s2;
    cin >> s1;
    
    if (n == 1 and s1.back() == 'P'){
      cout << 0 << endl;
      continue;
    }

    if (s1.back() == 'A'){
      cout << 0 << endl;
      continue;
    }

    s2 = s1;
    int t = 1;
    while (1){
      for (int i = 0; i < n-1; ++i){
        if (s1[i] == 'A'){
          s2[i+1] = 'A';
          s2[i] = 'A';
        }
      }
      if (s2.back() == 'A'){
        break;
      }
      t++;
      if (s1 == s2) break;
      s1 = s2;
    }
    cout << t << endl;
  }
  return 0;
}
