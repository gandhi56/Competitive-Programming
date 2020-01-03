#include <iostream>
using namespace std;
int main(){
  int t;
  cin >> t;

  while (t--){
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; ++i) cin >> arr[i];

    if (n&1){
      int ans = arr[0];
      for (int i = 2; i < n; i += 2){
        ans ^= arr[i];
      }
      cout << ans << endl;
    }
    else{
      cout << 0 << endl;
    }

  }
  return 0;
}
