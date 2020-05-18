// BOJ_10828_스택

#include <iostream>
#include <stack>
#include <string>
#define endl "\n"
using namespace std;

int main() {
    int N, X;
    stack<int> st;
    string inst;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> inst;
        if (inst == "push") {
            cin >> X;
            st.push(X);
        } else if (inst == "pop") {
            if (st.empty())
                cout << -1 << endl;
            else {
                X = st.top();
                st.pop();
                cout << X << endl;
            }
        } else if (inst == "size")
            cout << st.size() << endl;
        else if (inst == "empty")
            cout << st.empty() << endl;
        else if (inst == "top") {
            if (st.empty())
                cout << -1 << endl;
            else {
                X = st.top();
                cout << X << endl;
            }
        }
    }
    return 0;
}