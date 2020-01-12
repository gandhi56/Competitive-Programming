#define INF 0x3f3f3f3f
#define MAXN 1000000001
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
    int a, b;
    cin >> a >> b;
    
    if (a == b){
      cout << 0 << endl;
      continue;
    }

    if (a > b)  swap(a, b);

    int cnt = 0;
    int num = b-a;
    cnt += num/5;
    num = num%5;
    cnt += num/2;
    num %= 2;
    cnt += num;
    cout << cnt << endl;

  }
  return 0;
}
