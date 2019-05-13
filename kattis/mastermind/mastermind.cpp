#include <iostream>
using namespace std;

int main(){
	int n;
	cin >> n;

	string a, b;
	cin >> a >> b;

	string aa = "";
	string bb = "";
	int r = 0, s = 0;
	for (int i =0 ; i < n; ++i){
		if (a[i] == b[i]){
			r++;
		}
		else{
			aa += a[i];
			bb += b[i];
		}
	}

	for (int i = 0; i < aa.length(); ++i){
		for (int j = 0; j < bb.length(); ++j){
			if (aa[i] == bb[j]){
				bb[j] = '#';
				s++;
				break;
			}
		}
	}
	cout << r << " " << s << endl;

	return 0;
}
