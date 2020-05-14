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
  
  int t;
  cin >> t;
  while (t--){
    int n;
    cin >> n;

    int ar[n];
    int tot = 0;
    for (int i =0 ; i <n; ++i)  cin >> ar[i];
    for (int i =0 ; i <n; ++i)  tot += ar[i];

    int m = 0, a = 0, b = 0;
    int tota = 0;
    int totb = 0;
    int i=-1;
    int j = n;
    bool p1 = true;

    while (tota + totb < tot){
      if (p1){
        a = 0;
        i++;
        while (i < j){
          a += ar[i];
          if (a > b)    break;
          i++;
        }
        tota += a;
      }
      else{
        b = 0;
        j--;
        while (i < j){
          b += ar[j];
          if (b > a)    break;
          j--;
        }
        totb += b;
      }
      p1 = !p1;
      m++;
    }

    cout << m << ' ' << tota << ' ' << totb << endl;

  }

  return 0;
}
