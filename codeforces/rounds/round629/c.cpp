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


int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  int t;
  cin >> t;
  while (t--){
    int n;
    cin >> n;
    
    string x;
    cin >> x;

    string a, b;
    bool f = false;
    for (int i = 0; i < n; ++i){
      if (x[i] == '2'){
        if (f){
          if (a < b){
            a.push_back('2');
            b.push_back('0');
          }
          else{
            a.push_back('2');
            b.push_back('0');
          }
        }
        else{
          a.push_back('1');
          b.push_back('1');
        }
      }
      else{
        if (a < b){
          a.push_back(x[i]);
          b.push_back('0');
        }
        else{
          b.push_back(x[i]);
          a.push_back('0');
        }
        if (x[i] == '1')    f = true;
      }
    }
    cout << a << endl;
    cout << b << endl;
  }
  return 0;
}
