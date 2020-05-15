// BOJ_1068_트리

#include <iostream>
#include <vector>

using namespace std;

vector<int> t[51];
int answer = 0;

void dfs(int n, int e) {
    if (t[n].size() == 0)
        answer++;
    for (int i = 0; i < t[n].size(); i++) {
        if (t[n][i] == e && t[n].size() == 1) {
            answer++;
            return;
        } else if (t[n][i] == e && t[n].size() != 1)
            continue;
        dfs(t[n][i], e);
    }
}

int main() {
    int n, e, in;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        if (num == -1) {
            in = i;
            continue;
        }
        t[num].push_back(i);
    }
    cin >> e;
    if (in == e)
        cout << answer;
    else {
        dfs(in, e);
        cout << answer;
    }
    return 0;
}
