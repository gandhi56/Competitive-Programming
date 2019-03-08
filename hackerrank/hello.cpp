#include <iostream>
using namespace std;

int main(){
	int b, n, m;
	cin >> b >> n >> m;

	int keyboard[n];
	int usb[m];
	for (int i = 0; i < n; ++i)	cin >> keyboard[i];
	for (int i =0  ;i < m; ++i)	cin >> usb[i];

	int spend = 0;

	for (int i =0 ; i < n; ++i){
		for (int j = 0; j < m; ++j){
			if (keyboard[i] + usb[j] <= b)
				spend = max(spend, keyboard[i] + usb[j]);
		}
	}

	if (spend == 0){
		cout << "-1" << endl;
	}
	else{
		cout << spend << endl;
	}
	return 0;
}
