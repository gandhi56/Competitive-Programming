#include <iostream>
using namespace std;

typedef unsigned long long ull;

int main(){
  int n;
  cin >> n;

  while (n--){
    ull x;
    ull m = (1LL << 60);
    cin >> x;
    while (!(x&m))  m >>= 1;  //msb
    cout <<  (ull)(x ^ ((m-1) | m)) << endl;
  }
  return 0;
}
