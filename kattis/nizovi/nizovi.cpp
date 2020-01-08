#include <bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin >> s;

	int idt = 0;
	bool first = false;
	for (auto c : s){
		if (c == '{'){
			for (int i = 0; i < idt; ++i)	cout << ' ';
			cout << c << endl;
			idt += 2;
			first = true;
		}
		else if (c == '}'){
			idt -= 2;
			for (int i = 0; i < idt; ++i)	cout << ' ';
			cout << endl << c << endl;
		}
		else if (c == ','){
			cout << c << endl;
			for (int i = 0; i < idt; ++i)	cout << ' ';
		}
		else{
			if (first){
				for (int i = 0; i < idt; ++i)	cout << ' ';
				first = false;
			}
			cout << c;
		}
	}

	return 0;
}
