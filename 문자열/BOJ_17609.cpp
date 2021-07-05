#include <iostream>
#define endl "\n"

using namespace std;

string s;
int rec(int p1, int p2, int chk) {
    if (p1 > p2)
        return chk;
    if (s[p1] == s[p2])
        return rec(p1 + 1, p2 - 1, chk);
    else if (chk == 0) {
        if (s[p1] == s[p2 - 1] && rec(p1, p2 - 1, chk + 1) != 2)
            return 1;
        else if (s[p1 + 1] == s[p2] && rec(p1 + 1, p2, chk + 1) != 2)
            return 1;
    }
    return 2;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> s;
        cout << rec(0, s.size() - 1, 0) << endl;
    }
    return 0;
}