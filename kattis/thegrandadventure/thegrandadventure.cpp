#include <iostream>
using namespace std;

int main(){
	int n;
	cin >> n;

	while (n--){
		string s;
		cin >> s;

		int m = 0;
		int i = 0;
		int g = 0;

		bool won = true;

		for (char c : s){
			if (c == '$'){
				m++;
			}
			else if (c == '|'){
				i++;
			}	
			else if (c == '*'){
				g++;
			}	
			else if (c == 't'){
				if (i >= 1){
					i--;
				}
				else{
					won = false;
					break;
				}
			}	
			else if (c == 'j'){
				if (g >= 1){
					g--;
				}
				else{
					won = false;
					break;
				}
			
			}	
			else if (c == 'b'){
				if (m >= 1){
					m--;
				}
				else{
					won = false;
					break;
				}
			
			}	
		}

		if (won and m == 0 and i == 0 and g == 0){
			cout << "YES" << endl;
		}
		else{
			cout << "NO" << endl;
		}

	}

	return 0;
}
