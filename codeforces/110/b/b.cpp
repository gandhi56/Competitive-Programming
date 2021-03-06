#define LIN cout << __LINE__ << endl;
#define INF 0x3f3f3f3f
#include <bits/stdc++.h>
using namespace std;

#define min3(a, b, c) min(a, min(b, c))
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;

  string s;
  for (int i = 0; i < min(n, 4); ++i)
    s.push_back('a'+i);

  int i = 0;
  while (sz(s)< n){
    s.push_back(s[i++]);
  }
  cout << s << endl;

  return 0;
}
