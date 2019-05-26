#include <iostream>
using namespace std;

int main(){
	int t;
	cin >> t;

	while (t--){
		int d, h, m;
		char c;
		cin >> c >> d >> h >> m;

		if (c == 'F'){
			m += d;
			while (m >= 60){
				m -= 60;
				h = (h+1)%24;
			}
		}
		else{
			m -= d;
			while (m < 0){
				m += 60;
				h--;
				if (h < 0) h = 23;
			}
		}
		cout << h << " " << m << endl;
	}
	return 0;
}
