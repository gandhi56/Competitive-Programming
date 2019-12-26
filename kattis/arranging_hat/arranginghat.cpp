#include <iostream>
using namespace std;

void change(string& a, string& b){
	int i =0 ;
	while (a[i] <= b[i]){
		
	}
}

int main(){
	int n, m;
	cin >> n >> m;

	string a[n];
	for (int i = 0; i < n; ++i){
		cin >> a[i];
	}

	for (int i = 0; i < n; ++i){
		for (int j = i+1; j < n; ++j){
			a[i] = min(a[i], a[j]);
		}
	}

	for (int i = 0; i < n; ++i){
		cout << a[i] << endl;
	}

	return 0;
}
