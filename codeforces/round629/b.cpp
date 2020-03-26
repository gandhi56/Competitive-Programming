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

void print(int n, int i, int j){
  for (int k = 0; k < n; ++k){
    if (k == i or k == j)   cout << 'b';
    else
      cout << 'a';
  }
  cout << endl;
}

string solve(int n, int k){
  string s;
  if (k == 1){
    for (int i =0 ; i < n-2; ++i)  s += "a";
    s += "bb";
    return s;
  }
  int N = n*(n-1)/2;
  if (k > N - n){
    s = "b" + solve(n-1, k-N+n-1);
  }else{
    s = "a" + solve(n-1, );
  }
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  int t;
  cin >> t;
  while (t--){
    int n, k;
    cin >> n >> k;
 
    string s;
    for (int i = 0; i < n-2; ++i)   s += "a";
    s += "bb";

    int i = n-2 , j = n-1;
    for (int kk = 1; kk <= k-1; ++kk){
      if (i+1 == j){
        i--;
        j = n-1;
      }
      else{
        j--;
      }
      //print(n,i,j);
    }

    print(n, i, j);

  }
  
  return 0;
}
