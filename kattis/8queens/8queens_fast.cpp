#define power2(x) (x != 0 && ((x&(x-1)) == 0))
#include <stdio.h>
#include <vector>
using namespace std;

int main(){
    short board[8];
    bool valid = true;
    char c;
    short x;
    int rowQueens;
    for (int i = 0; i < 8; ++i){
        x = 0;  // row bits
        int j = 0; // column
        int rowQueens = 0;
        while (j < 8){
            scanf("%c", &c);
            if (!valid) continue;
            if (c == '\0'){
                break;
            }
            else if (c == '*'){
                if (rowQueens >= 1){
                    valid = false;
                }
                else{
                    x |= (1<<(8-1-i));
                    rowQueens++;
                }
            }
            j++;
        }
        board[i] = x;
        scanf("%c", &c);
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

    printf("%s\n", valid?"valid":"invalid");

	return 0;
}
