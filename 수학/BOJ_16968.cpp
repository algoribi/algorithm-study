#include <iostream>

using namespace std;

int main() {
    string s;
    cin >> s;
    int ans = 1;
    char fl = s[0];
    if (fl == 'd')
        ans *= 10;
    else
        ans *= 26;
    for (int i = 1; i < s.size(); i++) {
        if (fl == 'c') {
            if (s[i] == 'c')
                ans *= 25;
            else
                ans *= 10;
        } else {
            if (s[i] == 'd')
                ans *= 9;
            else
                ans *= 26;
        }
        fl = s[i];
    }
    cout << ans;
    return 0;
}