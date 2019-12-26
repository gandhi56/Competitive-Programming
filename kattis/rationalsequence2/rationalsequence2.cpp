#include <iostream>
using namespace std;
int main(){
	int t;
	cin >> t;
	while (t--){
		int k, p, q;
		char c;
		cin >> k >> p >> c >> q;

		string ans;
		while (p != 1 or q != 1){
			if (p > q){
				p -= q;
				ans += "1";
			}
			else{
				q -= p;
				ans += "0";
			}
		}
		ans += "1";

		int num = 0;
		for (int i = 0; i < ans.size(); ++i){
			if (ans[i] == '1'){
				num += (1 << i);
			}
		}

		cout << k << " " << num << endl;
	}

	return 0;
}
