#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;
	cin >> s;

	int pos[s.length()];

	stack<int> stk;
	int n = 0;
	for (unsigned int i = 0; i < s.length(); ++i){
		pos[i] = -1;
		if (s[i] == '('){
			stk.push(i);
		}
		else if (s[i] == ')'){
			pos[stk.top()] = i;
			pos[i] = stk.top();
			stk.pop();
			++n;
		}
	}

	set<string> ans;

	for (int x = 0; x < (1<<n)-1; ++x){
		int bid = 0;
		bool tp[s.length()];
		memset(tp, false, sizeof(tp));
		for (unsigned int i = 0; i < s.length(); ++i){
			if (s[i] == '('){
				if (x&(1<<bid)){
					tp[i] = true;
					tp[pos[i]] = true;
				}
				++bid;
			}
			else if (s[i] == ')'){

			}
			else{
				tp[i] = true;
			}
		}

		string ss;
		for (unsigned int i = 0; i < s.length(); ++i){
			if (tp[i])	ss.push_back(s[i]);
		}
		ans.insert(ss);
	}

	for (auto ss : ans)	
		cout << ss << endl;

	return 0;
}
