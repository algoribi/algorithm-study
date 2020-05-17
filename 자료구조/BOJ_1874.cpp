// BOJ_1874_스택 수열

#include <stdio.h>

#include <stack>
#include <vector>

using namespace std;

int main() {
    int n, i, m, cnt = 1;
    stack<int> st;
    vector<char> ans;
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &m);
        while (st.empty() || st.top() < m) {
            st.push(cnt);
            cnt++;
            ans.push_back('+');
        }
        if (st.top() == m) {
            st.pop();
            ans.push_back('-');
        } else {
            ans.clear();
            break;
            printf("NO\n");
        }
    }
    if (ans.empty()) {
        printf("NO\n");
        return -1;
    }
    for (i = 0; i < ans.size(); i++) {
        printf("%c\n", ans[i]);
    }
    return 0;
}