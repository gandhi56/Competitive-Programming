#include <iostream>
using namespace std;

int main(){
	int n;
	cin >> n;	// number of tiles in each row

	int back1[n+1];
	int back2[n+1];
	int front1[n+1];
	int front2[n+1];

	for (int i = 1; i <= n; ++i)	cin >> back1[i];
	for (int i = 1; i <= n; ++i)	cin >> back2[i];
	for (int i = 1; i <= n; ++i)	cin >> front1[i];
	for (int i = 1; i <= n; ++i)	cin >> front2[i];

	return 0;
}
