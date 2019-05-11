#include <iostream>
#include <map>
using namespace std;

int main(){
	map<string,int> vars;
	string t;
	while (cin >> t){
		if (t == "define"){
			int val;
			string var;
			cin >> val >> var;
			if (vars.count(var) == 0)	vars.insert({var, 0});
			vars[var] = val;
		}
		else{
			string a, b, c;
			cin >> a >> b >> c;

			if (vars.count(a) == 0 or vars.count(c) == 0){
				cout << "undefined" << endl;
				continue;
			}

			if (vars[a] < vars[c]){
				if (b == "<"){
					cout << "true" << endl;
				}
				else{
					cout << "false" << endl;
				}
			}
			else if (vars[a] > vars[c]){
				if (b == ">"){
					cout << "true" << endl;
				}
				else{
					cout << "false" << endl;
				}
			}
			else{
				if (b == "="){
					cout << "true" << endl;
				}
				else{
					cout << "false" << endl;
				}
			}
		}
	}

	return 0;
}
