#include <bits/stdc++.h>
using namespace std;

long long find(long long* par, long long u){
  if (par[u] == u)
    return u;
  return par[u] = find(par, par[u]);
}

long long value(long long n){
  long long t1 = n*(n+1)*(2*n+1)/6;
  long long t2 = n*(n+1)/2;
  return t1 - t2;
}

int main(){
  long long q;
  cin >> q;
  while (q--){
    long long n, m;
    cin >> n >> m;
  
    long long par[n+1];
    long long f[n+1];
    for (long long i = 1; i <= n; ++i){
      par[i] = i;
      f[i] = 1;
    }

    for (long long i = 0; i < m; ++i){
      long long u, v;
      cin >> u >> v;
      long long pu = find(par, u);
      long long pv = find(par, v);
      if (pu != pv){
        par[pv] = pu;
        f[pu] += f[pv];
      }
    }

    vector<long long> ans;
    for (long long i = 1; i <= n; ++i){
      if (par[i] == i)  ans.push_back(f[i]);
    }

    long long curr = 0;
    long long res = 0;
    long long tot = 0;
    sort(ans.begin(), ans.end(), greater<long long>());
    for (long long i =0 ; i < ans.size(); ++i){
      curr += (ans[i] - 1);
      res += value(ans[i]) + tot * (ans[i] - 1);
      tot += (ans[i] * (ans[i] -1));
    }
    res += ((m - curr) * tot);
    cout << res << endl;
  
  }
  return 0;
}
