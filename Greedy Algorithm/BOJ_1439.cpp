// algorithm study
// BOJ_1439_뒤집기

#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    string s;
    cin >> s;
    int count0 = 0, count1 = 0;
    char fl = s[0];
    for (char c : s) {
        if (fl != c) {
            if (fl == '0')
                count0++;
            else
                count1++;
            fl = c;
        }
    }
    if (fl == '0')
        count0++;
    else
        count1++;
    cout << min(count0, count1);
    return 0;
}