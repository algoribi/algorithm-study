// algorithm study
// BOJ_1918_후위 표기식

#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    map<char, int> m;
    m['+'] = 0;
    m['-'] = 0;
    m['*'] = 1;
    m['/'] = 1;
    m['('] = -1;

    string s, answer;
    vector<char> v;
    cin >> s;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(')
            v.push_back(s[i]);
        else if (s[i] >= 'A' && s[i] <= 'Z')
            answer.push_back(s[i]);
        else if (s[i] == ')') {
            while (v.back() != '(') {
                answer.push_back(v.back());
                v.pop_back();
            }
            v.pop_back();
        } else {
            while (!v.empty() && m[v.back()] >= m[s[i]]) {
                answer.push_back(v.back());
                v.pop_back();
            }
            v.push_back(s[i]);
        }
    }

    while (!v.empty()) {
        answer.push_back(v.back());
        v.pop_back();
    }

    cout << answer;

    return 0;
}