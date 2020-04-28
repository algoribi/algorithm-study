// algorithm study
// BOJ_1764_듣보잡

#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    map<string, int> mp;
    vector<string> answer;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        mp.insert(make_pair(s, 1));
    }
    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
        if (mp.find(s) != mp.end())
            answer.push_back(s);
    }

    sort(answer.begin(), answer.end());
    cout << answer.size() << "\n";
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << "\n";
    }
    return 0;
}