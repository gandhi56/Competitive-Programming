#include <iostream>
using namespace std;
int main(){
  int n, k;
  cin >> n >> k;

  int m = -1;
  while (n--){
    int x;
    cin >> x;
    m = max(m, x);
  }
  cout << max(0, m-k) << endl;
  return 0;
}