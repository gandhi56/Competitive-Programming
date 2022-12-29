#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

typedef std::vector<char> State;

void print_state(State& s) {
    cout << s[0] << s[1] << s[2] << '\n';
    cout << s[3] << s[4] << s[5] << '\n';
    cout << s[6] << s[7] << s[8] << '\n';
}

void read_state(State& s) {
    int i = 0;
    while (i < 9) {
        char c;
        cin >> c;
        if (c == '\n')	cin >> c;
        s[i++] = c;
    }
}


pair<int, bool> eval(State s) {
    // check for endgame
    unordered_map<char, int> M;
    M['x'] = 1;
    M['o'] = -1;

    // horizontal
    if (s[0] == s[1] && s[1] == s[2] && s[0] != '.')
        return {M[s[0]], true};
    if (s[3] == s[4] && s[4] == s[5] && s[3] != '.')
        return {M[s[3]], true};
    if (s[6] == s[7] && s[7] == s[8] && s[6] != '.')
        return {M[s[6]], true};
    
    // vertical
    if (s[0] == s[3] && s[3] == s[6] && s[0] != '.')
        return {M[s[0]], true};
    if (s[1] == s[4] && s[4] == s[7] && s[1] != '.')
        return {M[s[1]], true};
    if (s[2] == s[5] && s[5] == s[8] && s[2] != '.')
        return {M[s[2]], true};

    // diagonal
    if (s[0] == s[4] && s[4] == s[7] && s[0] != '.')
        return {M[s[4]], true};
    if (s[2] == s[4] && s[4] == s[6] && s[2] != '.')
        return {M[s[4]], true};

    // is there a move to play?
    for (int i =0 ; i < 9; ++i)
        if (s[i] == '.')
            return {0, false};

    return {0, true};   // draw
}

pair<int, int> best_move(State s, char p) {
    // evaluate state, return value if done
    auto score = eval(s);
    if (score.second)
        return {score.first, 123};

    int bv = (p == 'x') ? -100 : 100;   // init best value
    int bm;
    for (int m = 0; m < 9; ++m) {
        if (s[m] != '.') continue;

        s[m] = p; // play move
        auto [v, _] = best_move(s, (p == 'x' ? 'o':'x'));

        if ((p == 'x' && v > bv) || (p == 'o' && v < bv)) {
            bv = v;
            bm = m;
        }

        s[m] = '.';   // clear last move
    }
    return {bv, bm};
}

int main() {
    State s;
    s.assign(9, '.');

    string in;
    cin >> in;

    s.assign(9, '.');
    while (1) {
        read_state(s);
        if (eval(s).second) break;
        auto [bv, bm] = best_move(s, 'x');
        s[bm] = 'x';
        cerr << "bv " << bv << '\n';
        print_state(s);
        if (eval(s).second) break;
    }

    return 0;
}
