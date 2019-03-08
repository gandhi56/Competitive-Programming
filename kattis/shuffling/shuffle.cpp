#include <iostream>
#include <vector>
using namespace std;

int n;
bool solved(vector<int>& v){
	for (int i =0 ; i < v.size(); ++i){
		if (v[i] != i)	return false;
	}
	return true;
}

vector<int> outshuffle(vector<int>& v){
	int i = 0;
	int mid = (int)(n / 2);
	int j = (int)(n / 2);
	if (n%2)	j++;
	vector<int> a;
	while (1){
		if (n%2 == 0 and j >= n)	break;
		if (n%2		 and i >= mid+1)	break;
		a.push_back(v[i]);
		if (j < n)	a.push_back(v[j]);
		i++;	j++;
	}
	return a;
}

vector<int> inshuffle(vector<int>& v){
	int i = 0;
	int mid = (int)(n / 2);
	int j = mid;
	if (n%2)	j++;
	vector<int> a;
	while (1){
		if (n%2 == 0 and j >= n)	break;
		if (n%2		 and i >= mid+1)	break;
		if (j < n)	a.push_back(v[j]);
		a.push_back(v[i]);
		i++;	j++;
	}
	return a;
}

void count(vector<int>& v, bool in){
	int c = 0;
	while (1){
		if (in){
			v = inshuffle(v);
		}
		else{
			v = outshuffle(v);
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
