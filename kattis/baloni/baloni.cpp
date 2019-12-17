#include <iostream>
#include <cstring>
using namespace std;

int main(){
	int n;
	cin >> n;

	int count[1000001];
	memset(count, 0, sizeof(count));
	while (n--){
		int x;
		cin >> x;

		if (count[x] == 0){
			count[x-1]++;
		}
		else{
			count[x-1]++;
			count[x]--;
		}
	}

	int ans = 0;
	for (int i =0 ; i < 1000001; ++i){
		ans += count[i];
	}
	cout << ans << endl;

	return 0;
}
