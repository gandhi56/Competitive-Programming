#include <iostream>
#include <string.h>
using namespace std;

bool ok[201];

int main(){
	int n;
	cin >> n;

	memset(ok, false, sizeof(ok));

	int last;
	for (int i = 0; i < n; ++i){
		int x;
		cin >> x;
		ok[x] = true;
		last = x;
	}

	bool good = true;
	for (int i = 1; i <= last; ++i){
		if (!ok[i])
			good = false;
	}

	if (good){
		cout << "good job" << endl;
	}
	else{
		for (int i = 1; i <= last; ++i){
			if (!ok[i])
				cout << i << endl;
		}
	}

	return 0;
}
