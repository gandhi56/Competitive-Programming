#include <iostream>
using namespace std;
int main(){
  int t;
  cin >> t;

  while (t--){
    int n;
    cin >> n;
    int h = 1;
    for (int i = 1; i <= n; ++i){
      h = (i&1 ? 2*h : h+1);
    }
    cout << h << endl;
  }
  return 0;
}
