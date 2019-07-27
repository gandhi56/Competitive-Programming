#include <iostream>
using namespace std;

typedef pair<int,int> ii;

int main(){
	int n;
	cin >> n;

	ii p[60];
	for (int i = 0; i < 60; ++i){
		p[i] = {i/20 + 1, (i%20)+1};
	}

	bool ok = false;
	for (int i = 0; i < 60 && !ok; ++i){
		
		
		int a = p[i].first * p[i].second;
		if (a == n){
			ok = true;
			
			if (p[i].first == 1){
				cout << "single ";
			}
			else if (p[i].first == 2){
				cout << "double ";
			}
			else{
				cout << "triple ";
			}
			cout << p[i].second << endl;
		}

		for (int j = 0; j < 60 && !ok; ++j){



			int b = p[j].first * p[j].second;

			if (a+b == n){
				ok = true;

				for (int t : {i, j}){
					if (p[t].first == 1){
						cout << "single ";
					}
					else if (p[t].first == 2){
						cout << "double ";
					}
					else{
						cout << "triple ";
					}
					cout << p[t].second << endl;
				}
			}
			for (int k = 0; k < 60 && !ok; ++k){
				int c = p[k].first * p[k].second;
				if (a+b+c == n){
					ok = true;

					for (int t : {i, j, k}){
						if (p[t].first == 1){
							cout << "single ";
						}
						else if (p[t].first == 2){
							cout << "double ";
						}
						else{
							cout << "triple ";
						}
						cout << p[t].second << endl;
					}
				}
			}
		}
	}

	if (!ok){
		cout << "impossible" << endl;
	}

	return 0;
}
