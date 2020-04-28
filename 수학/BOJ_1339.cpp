// algorithm_study
// BOJ_1339_단어 수학

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool sort_v(int a, int b) {
    if (a == b)
        return a > b;
    return a > b;
}

int main() {
    int n;
    cin >> n;
    int count[30] = {0};
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int num = 10;
        if (s.size() > 0)
            count[s[s.size() - 1] - 'A'] += 1;
        if (s.size() == 1)
            continue;
        for (int j = s.size() - 2; j >= 0; j--) {
            count[s[j] - 'A'] += num;
            num *= 10;
        }
    }

    vector<int> v;
    for (int i = 0; i < 30; i++) {
        if (count[i] > 0)
            v.push_back(count[i]);
    }

    sort(v.begin(), v.end(), sort_v);

    int answer = 0;
    for (int i = 0; i < v.size(); i++) {
        answer += (v[i] * (9 - i));
    }

    cout << answer;

    return 0;
}