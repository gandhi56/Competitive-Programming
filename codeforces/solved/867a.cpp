#define INF 0x3f3f3f3f
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll, ll> pii;
typedef vector< vector<int> > vii;

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  string s;
  cin >> s;

  int g = 0,f = 0;
  for (int i = 0; i < n-1; ++i){
    if (s[i] == 'S' and s[i+1] == 'F')  g++;
    if (s[i] == 'F' and s[i+1] == 'S')  f++;
  }

  cout << (g>f?"yes":"no") << endl;

  return 0;

}
