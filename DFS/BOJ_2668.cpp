#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n, num[110], visit[110] = {0}, save[110] = {0}, fl = 0;
vector<int> answer;

void dfs(int i) {
    visit[i] = 1;
    save[i] = 1;
    if (save[num[i]] == 1) {
        fl = num[i];
        answer.push_back(i);
        return;
    } else if (visit[num[i]] == 1 || num[i] == num[num[i]])
        return;
    else {
        dfs(num[i]);
        if (fl == i) {
            fl = 0;
            answer.push_back(i);
        } else if (fl != 0)
            answer.push_back(i);
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> num[i];
        if (num[i] == i)
            answer.push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        if (num[i] == i || visit[i] != 0)
            continue;
        dfs(i);
        for (int j = 0; j <= 100; j++) {
            save[j] = 0;
        }
    }
    sort(answer.begin(), answer.end());
    cout << answer.size() << "\n";
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << "\n";
    }
    return 0;
}