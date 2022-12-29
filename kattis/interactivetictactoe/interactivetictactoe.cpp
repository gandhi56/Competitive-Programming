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
        if (c == '\n')  cin >> c;
        s[i++] = c;
    }
}

pair<int, bool> eval(State s) {
    // check for endgame
    unordered_map<char, int> M;
    M['x'] = 1;
    M['o'] = -1;

    auto match = [&](int i, int j, int k) {
        return s[i] == s[j] && s[j] == s[k] && s[i] != '.';
    };

    if (match(0,1,2) || match(0,3,6))
        return {M[s[0]], true};
    if (match(2,5,8) || match(6,7,8))
        return {M[s[2]], true};
    if (match(0,4,8) || match(2,4,6) || match(3,4,5) || match(1,4,7))
        return {M[s[4]], true};

    // is there a move to play?
    for (int i =0 ; i < 9; ++i)
        if (s[i] == '.')
            return {0, false};

    return {0, true};   // draw
}

// returns {best value, best move}
pair<int, int> best_move(State s, char p) {
    auto [score, done] = eval(s);
    if (done)   return {score, 123};

    int bv, bm;
    bv = (p == 'x' ? -100 : 100);
    for (int m = 0; m < 9; ++m) {
        if (s[m] != '.')    continue;
        s[m] = p;   // play move
        auto [v, _] = best_move(s, (p == 'x' ? 'o':'x'));
        s[m] = '.'; // undo move

        if ((p == 'x' && v > bv) || (p == 'o' && v < bv)) {
            bv = v;
            bm = m;
        }
    }
    return {bv, bm};
}

int main() {
    State s;
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
