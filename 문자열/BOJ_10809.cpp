#include <iostream>

using namespace std;

int main() {
    string s;
    cin >> s;
    int eng[30] = {0};
    for (int i = 0; i < s.size(); i++) {
        if (eng[s[i] - 'a'] == 0)
            eng[s[i] - 'a'] = i + 1;
    }
    for (int i = 0; i < 26; i++) {
        if (eng[i] == 0)
            cout << -1 << " ";
        else
            cout << eng[i] - 1 << " ";
    }
    return 0;
}