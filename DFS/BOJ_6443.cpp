#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

set<string> ans;
string st;

void dfs(int eng[30], string s) {
    if (s.size() == st.size()) {
        if (ans.find(s) == ans.end())
            ans.insert(s);
        return;
    }
    for (int i = 0; i < 30; i++) {
        if (eng[i] != 0) {
            s.push_back(i + 'a');
            eng[i]--;
            dfs(eng, s);
            eng[i]++;
            s.pop_back();
        }
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> st;
        int eng[30] = {0};
        for (int j = 0; j < st.size(); j++)
            eng[st[j] - 'a']++;
        dfs(eng, "");
        for (auto it = ans.begin(); it != ans.end(); it++) 
            cout<<*it<<"\n";
        ans.clear();
    }

    return 0;
}