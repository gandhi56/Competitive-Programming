#include <iostream>
#include <cmath>
using namespace std;

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string s;
	cin >> s;

	if (s.size() < 4){
		int num = atoi(s.c_str());
		if (num == 1){
			cout << 1 << endl;
		}
		else if (num == 2){
			cout << 2 << endl;
		}
		else if (num == 6){
			cout << 3 << endl;
		}
		else if (num == 24){
			cout << 4 << endl;
		}
		else if (num == 120){
			cout << 5 << endl;
		}
		else if (num == 720){
			cout << 6 << endl;
		}
	}
	else{
		int num = 6;
		double logSum = 4 * log10(2) + 2*log10(3) + log10(5);
		while (1){
			logSum += log10(++num);
			if (logSum > s.size()){
				cout << num - 1 << endl;
				break;
			}
		}
	}
	return 0;
}
