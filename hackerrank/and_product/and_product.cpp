#include <iostream>
using namespace std;
typedef unsigned int uint;

uint msb(int x){
  uint m = 1<<31;
  while (!(x&m))  m >>= 1;
  return m;
}

int main(){
  uint n;
  cin >> n;

  while (n--){
    uint a, b;
    cin >> a >> b;
    // zero out the bits of the difference b - a

  }
  return 0;
}
