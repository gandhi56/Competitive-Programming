#include <iostream>
using namespace std;

int main(){
	unsigned long long s = 0;
	int n;
	cin >> n;

	while (n--){
		char c;
		cin >> c;
		if (c == 'O')	s = (s|1)<<1;
		else			s <<= 1;
	}
	s >>= 1;

	cout << s << endl;

	return 0;
}
