// algorithm study
// BOJ_1305_광고

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int num, j = 0;
    string s;
    cin >> num >> s;
    vector<int> fail(s.size(), 0);
    for (int i = 1; i < s.size(); i++) {
        while (j > 0 && s[i] != s[j])
            j = fail[j - 1];
        if (s[i] == s[j])
            fail[i] = ++j;
    }
    cout << num - fail[num - 1];
    return 0;
}