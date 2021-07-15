#include <iostream>
#include <string>

using namespace std;

int ans = 0;
void kmp(string s) {
    int table[5005] = {0};
    int j = 0;
    for (int i = 1; i < s.size(); i++) {
        while (j > 0 && s[i] != s[j])
            j = table[j - 1];
        if (s[i] == s[j])
            table[i] = ++j;
        if (table[i] > ans)
            ans = table[i];
    }
}

int main() {
    string s, re_s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        re_s = s.substr(i, s.size());
        kmp(re_s);
    }
    cout << ans;
    return 0;
}