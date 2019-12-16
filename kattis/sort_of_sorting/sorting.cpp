#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const string& a, const string& b){
	if (a[0] == b[0])	return a[1] < b[1];
	return a[0] < b[0];
}

void bubble(vector<string>& names){
	for (int i = 0; i < names.size(); ++i){
		for (int j = i + 1; j < names.size(); ++j){
			if (names[i].substr(0,2) > names[j].substr(0,2)){
				//cout << "swapping " << names[i]  << " and ";
				//cout << names[j] << endl;
				string tmp = names[i];
				names[i] = names[j];
				names[j] = tmp;
			}
		}
	}
}



int main(){
	int n;
	while (cin >> n){
		if (n == 0)	break;
		
		vector<string> names;
		for (int i = 0; i < n; ++i){
			string a;
			cin >> a;
			names.push_back(a);
		}

		stable_sort(names.begin(), names.end(), cmp);
		//bubble(names);
		for (string a : names)	cout << a << endl;
		cout << endl;
	}
	return 0;
}
