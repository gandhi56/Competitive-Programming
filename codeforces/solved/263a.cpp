#define INF 0x3f3f3f3f
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll, ll> pii;
typedef vector< vector<int> > vii;

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  int m[5][5];
  for (int i = 0; i < 5; ++i)
    for (int j = 0; j < 5; ++j)
      cin >> m[i][j];

  int r, c;
  for (int i = 0; i < 5; ++i){
    for (int j = 0; j < 5; ++j){
      if (m[i][j] == 1){
        r = i;
        c = j;
      }
    }
  }

  cout << abs(r-2) + abs(c-2) << endl;

  return 0;
}
