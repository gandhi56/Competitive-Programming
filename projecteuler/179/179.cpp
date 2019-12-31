
#define MAXN 10000000-1
#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  scanf("%d", &t);
  while (t--){
    int n;
    scanf("%d", &n);
    vector<int> primes(n+1);
    for (int i = 2; i <= n; ++i)  primes[i] = i;

    for (int p = 2; p*p <= n; ++p){
      if (primes[p] == p){
        for (int q = 2*p; q <= n; q += p)
          primes[q] = p;
      }
    }

    // compute tau
    vector<int> tau(n+1);
    tau[1] = 1;
    for (int k = 2; k <= n; ++k){
      int s = 1, p = primes[k], m = k;
      while (m % p == 0){
        m /= p;
        s++;
      }
      tau[k] = s*tau[m];
    }

    int cnt = 0;
    for (int k = 2; k < n; ++k){
      if (tau[k] == tau[k+1]) ++cnt;
    }
    cout << cnt << endl;
  }

  return 0;
}
