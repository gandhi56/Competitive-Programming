#include <iostream>
using namespace std;
int main(){
  int q;
  cin >> q;

  while (q--){
    int a, b, c;
    cin >> a >> b >> c;
    if (abs(a-c) < abs(b-c)){
      cout << "Cat A" << endl;
    }
    else if (abs(a-c) > abs(b-c)){
      cout << "Cat B" << endl;
    }
    else{
      cout << "Mouse C" << endl;
    }
  }

  return 0;
}
