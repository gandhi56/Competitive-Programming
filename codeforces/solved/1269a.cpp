#define MAXN 1000000000
#define INF 0x3f3f3f3f
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll, ll> pii;
typedef vector< vector<int> > vii;

bool iscomp(int x){
  for (int d = 2; d*d <= x; ++d){
    if (x%d == 0) return true;
  }
  return false;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  int n;
  cin >> n;
  
  for (int b = 2; b <= MAXN; ++b){
    int a = n+b;
    if (iscomp(a) and iscomp(b)){
      cout << a << ' ' << b << endl;
      return 0;
    }
  }
  
  return 0;
}
