#include <iostream>
#include <bitset>

using namespace std;

void print_bits(bitset<32>& val, bitset<32>& marked){
	for (int i = 31; i >= 0; --i){
		if (marked[i]){
			cout << val[i];
		}
		else{
			cout << "?";
		}
	}
	
	cout << endl;
}
int main(){
	int n;
	while (cin >> n){
		if (n == 0)	break;
		
		bitset<32> val;
		bitset<32> marked;
		
		marked.reset();
		
		while (n--){
			string s;
			cin >> s;
			if (s == "SET"){
				int i;
				cin >> i;
				marked.set(i, 1);
				val.set(i, 1);
			}
			else if (s == "CLEAR"){
				int i;
				cin >> i;
				marked.set(i, 1);
				val.set(i, 0);
			}
			else if (s == "OR"){
				int i, j;
				cin >> i >> j;
				if ((marked[i] and val[i]) or (marked[j] and val[j])){
					val.set(i, 1);
					marked.set(i, 1);
				}
				else if ((marked[i]and!val[i])and(marked[j]and!val[j])){
					val.set(i, 0);
					marked.set(i, 1);
				}
				else{
					marked.set(i, 0);
				}
			}
			else if (s == "AND"){
				int i, j;
				cin >> i >> j;
				if ((marked[i] and val[i])and(marked[j]and val[j])){
					val.set(i, 1);
					marked.set(i, 1);
				}
				else if ((marked[i] and !val[i]) or (marked[j] and !val[j])){
					val.set(i, 0);
					marked.set(i, 1);
				}
				else{
					marked.set(i, 0);
				}

			}
		}

		print_bits(val, marked);
	}

	return 0;
}
