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
  
  int t;
  cin >> t;
  while (t--){
    int n;
    cin >> n;

    string s;
    cin >> s;

    int time = 0;
    while (1){
      int cnt = 0;
      //string ss = s;
      for (int i = n-1; i-1 >= 0;--i){
        if (s[i-1] == 'A' and s[i] != 'A'){
          s[i-1] = 'A';
          s[i] = 'A';
          cnt++;
        }
      }
      //cout << ss << endl;
      //s = ss;
      if (cnt){
        time++;
      }
      else{
        break;
      }
    }
    cout << time << endl;
  }

  return 0;
}
