#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

int main(){
	int n;
	cin >> n;

	unordered_map<char, bool> v;
	for (int i =0 ; i < n; ++i){
		char c;
		cin >> c;
		v.insert({'A'+i, (c == 'T' ? true : false)});
	}

	char c;
	stack<bool> s;
	bool value;
	while (cin >> c){
		if (c == '-'){
			bool u;
			u = s.top(); s.pop();
			s.push(!u);
		}
		else if (c == '*'){
			bool u, v;
			u = s.top(); s.pop();
			v = s.top(); s.pop();
			s.push(u&v);
		}
		else if (c == '+'){
			bool u, v;
			u = s.top(); s.pop();
			v = s.top(); s.pop();
			s.push(u|v);
		}
		else{
			s.push(v[c]);
		}
	}

	cout << (s.top()?'T':'F') << endl;

	return 0;
}
