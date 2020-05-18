// algorithm study
// BOJ_9375_패션왕 신해빈

#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        map<string, int> m;
        for (int j = 0; j < n; j++) {
            string s1, s2;
            cin >> s1 >> s2;
            if (m.find(s2) == m.end())
                m.insert(make_pair(s2, 1));
            else
                m[s2]++;
        }
        int answer = 1;
        for (auto it = m.begin(); it != m.end(); it++) {
            answer *= it->second + 1;
        }
        cout << answer - 1 << "\n";
    }
}