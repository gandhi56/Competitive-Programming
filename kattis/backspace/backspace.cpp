#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	string s;
	char c;
	while (scanf("%c", &c) != EOF){
		if (c == '<'){
			s.pop_back();
		}
		else if (c == '\n'){
			break;
		}
		else{
			s.push_back(c);
		}
	}

	cout << s << endl;

	return 0;
}
