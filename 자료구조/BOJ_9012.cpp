// BOJ_9012_괄호

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    int num, ind, co;
    string t;
    stack<char> s;
    cin >> num;

    for (int i = 0; i < num; i++) {
        cin >> t;
        ind = 0;
        co = 0;

        if (t.size() < 1) {
            cout << "NO" << endl;
            continue;
        } else if (t.size() > 50) {
            cout << "NO" << endl;
            continue;
        }
        for (int j = 0; j < t.size(); j++) {
            if (t[j] == '(') {
                s.push(t[j]);
                co++;
            } else if (t[j] == ')') {
                if (s.empty()) {
                    ind = 1;
                    break;
                } else {
                    s.pop();
                    co--;
                }
            } else
                ind = 2;
        }
        if (s.empty() && ind == 0)
            cout << "YES" << endl;
        else {
            cout << "NO" << endl;
            for (co; co > 0; co--) {
                s.pop();
            }
        }
    }
    return 0;
}