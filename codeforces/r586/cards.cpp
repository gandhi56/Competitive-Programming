#include <iostream>
#include <unordered_map>
using namespace std;

int main(){
	int n;
	cin >> n;

	unordered_map<char, int> count;
	count['z'] = 0;
	count['e'] = 0;
	count['r'] = 0;
	count['o'] = 0;
	count['n'] = 0;

	string s;
	cin >> s;

	for (char c : s){
		count[c]++;
	}

	int ones = min(count['n'], min(count['e'], count['o']));
	count['o'] -= ones;
	count['n'] -= ones;
	count['e'] -= ones;
	int zeros = min(count['z'], min(count['e'], min(count['r'], count['o'])));

	while (ones--){
		cout << 1 << " ";
	}

	while (zeros--){
		cout << 0 << " ";
	}

	return 0;
}
