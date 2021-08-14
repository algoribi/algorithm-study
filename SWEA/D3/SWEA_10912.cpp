#include <iostream>
#include <map>
#define endl "\n"

using namespace std;

int main() {
    int test_case;
    cin >> test_case;
    for (int t = 1; t <= test_case; t++) {
        string s;
        cin >> s;
        map<char, int> m;
        for (char c : s) {
            if (m.find(c) == m.end())
                m.insert({c, 1});
            else
                m[c]++;
        }
        cout << "#" << t << " ";
        int chk = 0;
        for (auto it = m.begin(); it != m.end(); it++) {
            if (it->second % 2 == 0)
                continue;
            cout << it->first;
            chk++;
        }
        if (chk == 0)
            cout << "Good";
        cout << endl;
    }
}