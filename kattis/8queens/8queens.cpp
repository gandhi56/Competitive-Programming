#define power2(x) (x != 0 && ((x&(x-1)) == 0))
#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<short> board;
    string s;
    bool valid = true;
    while (cin >> s){
        short x = 0;
        for (int i = 0; i < s.length(); ++i){
            if (s[i] == '*'){
                x |= (1<<(s.length()-i-1));
            }
        }
        if (power2(x)){
            board.push_back(x);
        }
        else{
            valid = false;
        }
    }

    if (valid){
        for (int i = 0; i < 8 and valid; ++i){
            for (int j = i + 1; j < 8 and valid; ++j){
                if (board[i]&board[j]){
                    valid = false;
                    break;
                }
            }
        }
    }

    if (valid){
        for (int i = 0; i < 8 and valid; ++i){
            for (int j = i+1; j < 8 and valid; ++j){
                if ((board[i] & (board[j] << (j-i))) or (board[i] & (board[j] >> (j-i)))){
                    valid = false;
                    break;
                }
            }
        }
    }

    cout << (valid?"valid":"invalid") << endl;

    return 0;
}