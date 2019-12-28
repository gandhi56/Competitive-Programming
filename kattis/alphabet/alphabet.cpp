#include <iostream>
#include <cstring>
using namespace std;

int main(){
	string s;
	cin >> s;
	s = "#" + s;

	string t = "abcdefghijklmnopqrstuvwxyz";
	t = "*" + t;

	int dp[s.size()][t.size()];
	memset(dp, 0, sizeof(dp));

	for (int i =0 ; i < s.size(); ++i){
		for (int j = 0; j < t.size(); ++j){
			if (i and j and s[i] == t[j])
				dp[i][j] = dp[i-1][j-1] + 1;
			if (i)	dp[i][j] = max(dp[i][j], dp[i-1][j]);
			if (j)	dp[i][j] = max(dp[i][j], dp[i][j-1]);
		}
	}

	cout << 26 - dp[s.size()-1][t.size()-1] << endl;

	return 0;
}
