#include <iostream>
using namespace std;
int main(){
	int lo = 1;
	int hi = 1000;
	string in;
	while (1){
		int mid = (lo + hi) / 2;
		cout << mid << endl;
		cin >> in;
		if (in == "lower"){
			hi = mid-1;
		}
		else if (in == "higher"){
			lo = mid+1;
		}
		else if (in == "correct"){
			break;
		}
	}

	return 0;
}
