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
  int a = 0;
  for (char c : s)
    if (c == 'a')
      a++;
  int b = s.length() - a;
  while (a <= (a+b)/2){
    b--;
  }
  cout << a+b << endl;
  return 0;
}
