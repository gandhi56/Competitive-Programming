#include <iostream>
#include <algorithm>
#define MOD 1000000007

using namespace std;

typedef unsigned long long ull;

int n, T;
ull a, b, c, t[10000];

int main(){
	cin >> n >> T;
	cin >> a >> b >> c >> t[0];

	for (int i = 1; i < n; ++i){
		t[i] = (((a*t[i-1] + b) % c) + 1) % MOD;
	}

	sort(t, t+n);

	for (int i = 0; i < n; ++i){
		cout << t[i] << " ";
	}
	cout << endl;

	int timeTaken = 0;
	int count =0;
	for (int i = 0; i < n; ++i){
		if (timeTaken + t[i] < T){
			timeTaken += t[i];
			count++;
		}
		else{
			break;
		}
	}

	cout << count << " " << timeTaken << endl;

	return 0;
}
