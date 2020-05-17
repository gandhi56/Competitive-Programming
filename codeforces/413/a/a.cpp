#define LIN cout << __LINE__ << endl;
#define INF 0x3f3f3f3f
#include <bits/stdc++.h>
using namespace std;

#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  
  int n, m, mn, mx;
  cin >> n >> m >> mn >> mx;

  set<int> temp;
  for (int i =0 ; i < m; ++i){
    int x;
    cin >> x;
    temp.insert(x);
  }

  if (*temp.begin() < mn or *temp.rbegin() > mx){
    cout << "Incorrect" << endl;
    return 0;
  }
  
  int off = 0;
  if (*temp.begin() != mn)   off++;
  if (*temp.rbegin() != mx) off++;

  if (n-m >= off){
    cout << "Correct" << endl;
  }
  else{
    cout << "Incorrect" << endl;
  }

  

  return 0;
}





