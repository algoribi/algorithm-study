// algorithm study
// BOJ_16939_2x2x2 큐브

#include <iostream>

using namespace std;

int t[6][8] = {{13, 14, 5, 6, 17, 18, 21, 22}, {15, 16, 7, 8, 19, 20, 23, 24}, {1, 3, 5, 7, 9, 11, 24, 22}, {2, 4, 6, 8, 10, 12, 23, 21}, {3, 4, 14, 16, 9, 10, 19, 17}, {1, 2, 13, 15, 11, 12, 20, 18}};
int cube[25] = {0};

int check(int c[]) {
    for (int i = 1; i < 25; i += 4) {
        if (c[i] == c[i + 1] && c[i + 1] == c[i + 2] && c[i + 2] == c[i + 3])
            continue;
        else
            return 0;
    }
    return 1;
}

int turn() {
    for (int i = 0; i < 6; i++) {
        int re[25] = {0};
        //turn_R
        for (int j = 1; j < 25; j++) {
            re[j] = cube[j];
        }
        for (int j = 0; j < 8; j += 2) {
            if (j == 6) {
                re[t[i][0]] = cube[t[i][j]];
                re[t[i][1]] = cube[t[i][j + 1]];
                break;
            }
            re[t[i][j + 2]] = cube[t[i][j]];
            re[t[i][j + 3]] = cube[t[i][j + 1]];
        }
        if (check(re) == 1)
            return 1;
        //turn_L
        for (int j = 1; j < 25; j++) {
            re[j] = cube[j];
        }
        for (int j = 7; j > 0; j -= 2) {
            if (j == 1) {
                re[t[i][7]] = cube[t[i][j]];
                re[t[i][6]] = cube[t[i][j - 1]];
                break;
            }
            re[t[i][j - 2]] = cube[t[i][j]];
            re[t[i][j - 3]] = cube[t[i][j - 1]];
        }
        if (check(re) == 1)
            return 1;
    }
    return 0;
}

int main() {
    for (int i = 1; i < 25; i++) {
        cin >> cube[i];
    }
    if (turn() == 1)
        cout << 1;
    else
        cout << 0;
    return 0;
}