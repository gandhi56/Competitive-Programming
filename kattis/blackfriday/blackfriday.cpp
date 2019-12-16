#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; ++i) cin >>a[i];

	bool found = false;
	int val = -1;
	int pos;
    for (int i = n-1; i >= 0; --i){
		int count =0 ;
		for (int j =0 ; j < n; ++j){
			if (a[j] == a[i])	count++;
		}

		if (count == 1){
			found = true;
			if (a[i] > val){
				val = a[i];
				pos = i;
			}
		}
	}
	if (found )cout << pos+1 << endl;
	if (!found)	cout << "none" << endl;
	
	return 0;
}
