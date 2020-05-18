// BOJ_2504_괄호의 값

#include <iostream>
#include <stack>

using namespace std;

int main() {
    string s;
    stack<char> st;
    int level = 1, memo[32];
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(' || s[i] == '[') {
            st.push(s[i]);
            level++;
            memo[level] = 0;
        } else if (s[i] == ')') {
            if (!st.empty() && st.top() == '(') {
                st.pop();
                level--;
                if (memo[level + 1] == 0)
                    memo[level + 1] = 1;
                memo[level] += memo[level + 1] * 2;
            } else {
                memo[1] = -1;
                break;
            }
        } else if (s[i] == ']') {
            if (!st.empty() && st.top() == '[') {
                st.pop();
                level--;
                if (memo[level + 1] == 0)
                    memo[level + 1] = 1;
                memo[level] += memo[level + 1] * 3;
            } else {
                memo[1] = -1;
                break;
            }
        }
    }
    if (memo[1] < 0)
        cout << 0;
    else
        cout << memo[1];

    return 0;
}