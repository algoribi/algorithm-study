// algorithm study
// BOJ_1541_잃어버린 괄호

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int ans(int a, int b, char c) {
    if (c == '-')
        return a - b;
    else
        return a + b;
}

int main() {
    string s;
    cin >> s;
    stack<int> num;
    stack<char> op;
    vector<int> save;
    s.push_back('/');
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= '0' && s[i] <= '9')
            save.push_back(s[i] - '0');
        else {
            int n = 0, t = 1;
            for (int j = 0; j < save.size() - 1; j++) {
                t = t * 10;
            }
            for (int j = 0; j < save.size(); j++) {
                n += save[j] * t;
                t /= 10;
            }
            save.clear();
            num.push(n);

            if (s[i] == '+')
                op.push(s[i]);
            else if (s[i] == '/')
                break;
            else {
                while (!op.empty()) {
                    int b = num.top();
                    num.pop();
                    int a = num.top();
                    num.pop();
                    num.push(ans(a, b, op.top()));
                    op.pop();
                }
                op.push(s[i]);
            }
        }
    }

    while (!op.empty()) {
        int b = num.top();
        num.pop();
        int a = num.top();
        num.pop();
        num.push(ans(a, b, op.top()));
        op.pop();
    }

    cout << num.top();

    return 0;
}