#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

ll f(ll x){
	return (x&1? 3*x+1 : x/2);
}

int main(){

	ll a, b;
	while (cin >> a >> b){
		if (a == 0)	break;

		vector<ll> aList, bList;
		aList.push_back(a);
		bList.push_back(b);
		while (aList.back() != 1)	aList.push_back(f(aList.back()));
		while (bList.back() != 1)	bList.push_back(f(bList.back()));

		int ia, ib;
		ia = aList.size() - 1;
		ib = bList.size() - 1;
		while (ia >= 0 and ib >= 0 and aList[ia] == bList[ib]){
			ia--;
			ib--;
		}

		cout << a << " needs " << ia+1 << " steps, " << b <<" needs ";
		cout << ib+1 << " steps, " << "they meet at " << aList[ia+1] << endl;

	}

	return 0;
}
