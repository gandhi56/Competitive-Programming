
// count all H-semi-primes between 1 and h, inclusively.


#include <iostream>
#include <vector>

using namespace std;

typedef unsigned long long ull;

bool is_semi(ull x){

	vector<ull> f;

	// prime factorize x, return true if exactly two
	// prime factors exist, of x.
	for (ull d = 2; d*d <= x; ++d){
		while (x%d == 0){
			f.push_back(d);
			x /= d;
		}
		if (f.size() > 2)	return false;
	}

	if (x > 2)	f.push_back(x);

	cout << x << " = ";
	for (auto m : f){
		cout << m << " x ";
	}
	cout << endl;

	if (f.size() == 2)	return true;
	return false;
}

int main(){
	cout << is_semi(45) << endl;
	cout << is_semi(81) << endl;

	ull h;

	while (1){
		cin >> h;
		if (!h)	break;

		int count =0 ;
		for (ull x = 1; x <= h; x += 4){
		
			if (is_semi(x)){
				cout << x << " is an H-semi-prime" << endl;
			}
			else{
				cout << x << " is not an H-semi-prime" << endl;
			}

		}
		//cout << h << " " << count << endl;

	}

	return 0;
}
