#include <iostream>
#include <cmath>
using namespace std;

#define E 2.71828182845904523536028747135266249775724709369995957496696762772407663
#define PI 3.141592653589793238462643383279502884197169399375105820974944592307816406286

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	while (cin >> n){
		if (n <= 3){
			cout << 1 << endl;
		}
		else{
			cout << (int)ceil(log10(2*PI*n)/2 + n*(log10(n/E))) << endl; 
		}
	}
	return 0;
}
