#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
  int t;
  cin >> t;

  while (t--){
    int n;
    cin >> n;

    int a[n];
    int yasser = 0;
    int adel = 0;
    int maxVal = INT_MIN;
    for (int i = 0; i < n; ++i){
      cin >> a[i];
      yasser += a[i];
      maxVal = max(maxVal, a[i]);
    }

    if (maxVal >= yasser){
      cout << "NO" << endl;
      goto done;
    }

    // find a segment whose sum is at least yasser
    /*
    int ps[n];
    ps[0] = a[0];
    for (int i = 1; i < n; ++i){
      ps[i] = ps[i-1] + a[i];
    }

    for (int i = 1; i < n; ++i){
      for (int j = i+1; j < n; ++j){
        int sum = ps[j] - ps[i-1];
        
      }
    }
    */

    for (int i = 0; i < n; ++i){
      ll sum = 0;
      for (int k = 0; i+k < n; ++k){
        if (k == n-1) continue;
        sum += a[i+k];
        if (sum > yasser){
          cout << "NO" << endl;
          goto done;
        }
      }
    }

    cout << "YES" << endl;
    done:;

  }

  return 0;
}
