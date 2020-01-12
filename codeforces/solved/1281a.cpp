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
    string s;
    cin >> s;
    int n = s.length();
    if (s.substr(n-2, 2) == "po"){
      cout << "FILIPINO" << endl;
    }
    else if (s.substr(n-4, 4) == "desu" or s.substr(n-4, 4) == "masu"){
      cout << "JAPANESE" << endl;
    }
    else if (s.substr(n-5, 5) == "mnida"){
      cout << "KOREAN" << endl;
    }
  }
  return 0;
}
