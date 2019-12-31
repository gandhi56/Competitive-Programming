#include <iostream>
using namespace std;
int main(){
  int w, p;
  cin >> w >> p;

  bool width[w+1] = {false};
  width[w] = true;
  int pa[p];
  for (int i =0; i < p; ++i){
    cin >> pa[i];
    width[pa[i]] = true;
    width[w - pa[i]] = true;
  }

  for (int i = 0 ; i < p; ++i){
    for (int j = i+1; j < p; ++j){
      width[pa[j] - pa[i]] = true;
    }
  }

  for (int i = 1; i <= w; ++i){
    if (width[i]){
      cout << i << ' ';
    }
  }
  cout << endl;

  return 0;
}