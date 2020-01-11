#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  while (t--){
    int n;
    cin >> n;
    int a[n];
    int curr = 1;
    for (int i =0;  i< n; ++i)  cin >> a[i];
    for (int i = 0; i < n; ++i){
      if (curr == a[i]){
        curr++;
      }
    }
    cout << n-curr+1 << endl;
  }
  return 0;
}
