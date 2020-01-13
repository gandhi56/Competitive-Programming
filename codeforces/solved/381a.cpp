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
  int a[n];
  for (int i = 0; i < n; ++i) cin >> a[i];
  int x = 0,y = 0;
  int i = 0, j = n-1;
  int turn = 1;
  while (i <= j){
    if (turn&1){
      if (a[i] > a[j]){
        x += a[i];
        i++;
      }
      else{
        x += a[j];
        j--;
      }
      turn++;
    }
    else{

      if (a[i] > a[j]){
        y += a[i];
        i++;
      }
      else{
        y += a[j];
        j--;
      }
      turn++;
    }
  }

  cout << x << ' ' << y << endl;

  return 0;
}
