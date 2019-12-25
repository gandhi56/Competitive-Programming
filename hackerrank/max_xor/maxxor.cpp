#include <iostream>
using namespace std;
int main(){
  int l, r;
  cin >> l >> r;

  int ans = -1;
  for (int a = l; a <= r; ++a){
    for (int b = a+1; b <= r; ++b){
      ans = max(ans, a^b);
    }
  }
  cout << ans << endl;
  return 0;
}
