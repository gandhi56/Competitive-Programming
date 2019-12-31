#include <iostream>
using namespace std;
int main(){
  int t;
  cin >> t;
  while (t--){
    int n, k;
    cin >> n >> k;
    
    int late = 0;
    for (int i = 0; i < n; ++i){
      int a;
      cin >> a;
      if (a > 0)  late++;
    }

    cout << (n-late < k ? "YES" : "NO") << endl;
  }
  return 0;
}
