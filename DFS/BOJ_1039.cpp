#include <iostream>
#include <queue>
#include <set>

using namespace std;

string s;
int k, answer = 0;
set<string> ss[12];

void dfs(int go) {
    if (go == k) {
        int number = 0, ten = 1;
        for (int i = s.size() - 1; i >= 0; i--) {
            number += (s[i] - '0') * ten;
            ten *= 10;
        }
        if (number > answer)
            answer = number;
        return;
    }
    for (int i = 0; i < s.size() - 1; i++) {
        for (int j = i + 1; j < s.size(); j++) {
            char s1 = s[i], s2 = s[j];
            s[i] = s2;
            s[j] = s1;
            if (ss[go].find(s) != ss[go].end()) {
                s[i] = s1;
                s[j] = s2;
                continue;
            }
            ss[go].insert(s);
            dfs(go+1);
            s[i] = s1;
            s[j] = s2;
        }
    }
}

int main() {
    cin >> s >> k;
    if (s.size() == 1 || (s.size() == 2 && s[1] == '0')) {
        cout << -1;
        return 0;
    }
    dfs(0);
    cout << answer;
    return 0;
}