// algorithm study
// BOJ_10546_배부른 마라토너

#include <iostream>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;
    map<string, int> m;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (m.find(s) != m.end())
            m[s]++;
        else
            m.insert(make_pair(s, 1));
    }
    for (int i = 0; i < n - 1; i++) {
        string s;
        cin >> s;
        if (m.find(s)->second == 1)
            m.erase(s);
        else
            m[s]--;
    }
    cout << m.begin()->first;
    return 0;
}