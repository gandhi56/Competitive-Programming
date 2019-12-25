#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

bool cmp(int a, int b){
	return a > b;
}

int main(){
	int h[6];
	bool marked[6];
	int h1, h2;
	memset(marked, false, sizeof(marked));
	for (int i =0; i < 6; ++i){
		cin >> h[i];
	}
	cin >> h1 >> h2;

	sort(h, h+6, cmp);

	for (int i = 0; i < 4; ++i){
		for (int j = i+1; j < 5; ++j){
			for (int k = j+1; k < 6; ++k){
				if (h[i]+h[j]+h[k] == h1){
					marked[i] = true;
					marked[j] = true;
					marked[k] = true;
					cout << h[i] << " " << h[j] << " " << h[k] << " ";
					for (int l = 0; l < 6; ++l){
						if (!marked[l]){
							cout << h[l] << " ";
						}
					}
					cout << endl;
					return 0;
				}
			}
		}
	}

	return 0;
}
