#include <iostream>
using namespace std;
int main(){
	int t;
	cin >> t;
	while (t--){
		int h, m;
		cin >> h >> m;
		
		int curr = h*60 + m;
		int goal = 24*60;
		cout << goal - curr << endl;

	}
	return 0;
}
