#include <iostream>
#include <set>
#include <cstring>
using namespace std;

string s;
int dp[1010][1010];

int findPalindromes(int start, int end){
/*
	if (i >= j)	return dp[i][j] = 1;
	if (dp[i][j] != -1)	return dp[i][j];
	findPalindromes(i+1, j);
	findPalindromes(i, j-1);
	findPalindromes(i+1, j-1);
	
	dp[i][j] = 0;
	if (s[i] == s[j] and dp[i+1][j-1] == 1)
		dp[i][j] = 1;
	return dp[i][j];
*/

	memset(dp, 0, sizeof(dp));
	for (int i = s.size()-1; i >= 0; --i){
		for (int j = 0; j < s.size(); ++j){
			if (i == j){
				dp[i][j] = 1;
			}
			else if (i < j){
				if (s[i] == s[j] and dp[i+1][j-1]){
					dp[i][j] = 1;
				}
			}
			else if (i > j){
				dp[i][j] = 1;
			}
		}
	}
	return dp[start][end];
}

void solve(){
	findPalindromes(0, s.size()-1);

	set<string> pals;
	for (int i = 0; i < s.size(); ++i){
		for (int j = i + 1; j < s.size(); ++j){
			if (dp[i][j] == 1){
				pals.insert(s.substr(i, j-i+1));
			}
		}
	}

	for (string p : pals){
		cout << p << endl;
	}
	cout << endl;

}

int main(){
	while (cin >> s){
		for (int i = 0; i < s.size()+5; ++i){
			for (int j = 0; j < s.size()+5; ++j){
				dp[i][j] = -1;
			}
		}
		solve();
	}

	return 0;
}
