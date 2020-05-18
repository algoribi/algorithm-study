// BOJ_10799_쇠막대기

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    string stick;
    cin >> stick;
    int ans = 0;
    stack<int> stk;
    for (int i = 0; i < stick.size(); i++) {
        if (stick[i] == '(' && stick[i + 1] == ')') {  //laser
            ans += stk.size();
            i++;
        } else if (stick[i] == '(')
            stk.push(1);
        else {
            ans += 1;
            stk.pop();
        }
    }

    cout << ans << '\n';
    return 0;
}