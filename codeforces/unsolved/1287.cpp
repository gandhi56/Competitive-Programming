#define INF 0x3f3f3f3f
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll, ll> pii;
typedef vector< vector<int> > vii;

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--){
    int n;
    cin >> n;
    string s1, s2;
    cin >> s1;
    
    if (s1.back() == 'A'){
      cout << 0 << endl;
      return 0;
    }

    s2 = s1;

    int t = 0;
    while (1){
      for (int i = 0; i < s1.length()-1; ++i){
        if (s1[i] == 'P'){
          s2[i] = 'P';
        }
        else{
          s2[i] = 'P';
          s2[i+1] = 'A';
        }
      }
      t++;
      if (s2.back() == 'P') break;
      s1 = s2;
    }
    cout << t << endl;
  }
  return 0;
}
