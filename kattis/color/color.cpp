#include <iostream>
#include <algorithm>
using namespace std;

typedef unsigned long long ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int s, c, k;
	cin >> s >> c >> k;

	int sock[s];
	for (int i = 0; i < s; ++i)	cin >> sock[i];

	sort(sock, sock+s);

	int i = 0;
	int sol = 0;
	while (i < s){
		int j = i + 1;
		while (j < s and j-i < c and sock[j] - sock[i] <= k)	j++;
		sol++;
		i = j;
	}

	cout << sol << endl;
	return 0;
}
