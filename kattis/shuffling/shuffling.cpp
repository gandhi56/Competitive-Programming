#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
bool solved(vector<int>& v){
	for (int i =0 ; i < v.size(); ++i){
		if (v[i] != i)	return false;
	}
	return true;
}


void merge(vector<int>& v, vector<int>& a, vector<int>& b){
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	while (!a.empty() or !b.empty()){
		if (!a.empty()){
			v.push_back(a.back());
			a.pop_back();
		}
		if (!b.empty()){
			v.push_back(b.back());
			b.pop_back();
		}
	}
}

void inshuffle(vector<int>& v){
	vector<int> a, b;
	int mid = (v.size())/2;
	for (int i = 0; i < v.size(); ++i){
		if (i < mid){
			a.push_back(v[i]);
		}
		else{
			b.push_back(v[i]);
		}
	}
	v.clear();
	merge(v, b, a);
}


void outshuffle(vector<int>& v){
	vector<int> a, b;
	int mid = (v.size()+1)/2;
	for (int i = 0; i < v.size(); ++i){
		if (i < mid){
			a.push_back(v[i]);
		}
		else{
			b.push_back(v[i]);
		}
	}
	v.clear();
	merge(v, a, b);
}

void count(vector<int>& v, bool in){
	int c = 0;
	while (1){
		if (in){
			inshuffle(v);
		}
		else{
			outshuffle(v);
		}
		c++;
		if (solved(v))	break;
	}
	cout << c << endl;
}

int main(){
	string s;
	cin >> n >> s;


	vector<int> v;
	for (int i = 0; i < n; ++i)	v.push_back(i);
	if (s == "in"){
		count(v, true);
	}
	else{
		count(v, false);
	}

	return 0;
}
