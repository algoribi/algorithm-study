#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <set>
#include <map>

using namespace std;

map<string, set<string>> m;
set<string> visit;

int dfs(string s) {
    visit.insert(s);
    if (m.find(s) == m.end())
        return 1;

    int counter = 0;
    for (auto it = m[s].begin(); it != m[s].end(); it++) {
        if (visit.find(*it) == visit.end())
            counter += dfs(*it);
    }
    return counter;
}

int main() {
    int n;
    while (1) {
        cin >> n;
        if (n == 0)
            break;
        string f;
        for (int i = 0; i < n; i++) {
            string str, sbuffer;
            cin >> str;
            str.pop_back();
           
            size_t prev = 0, cur;
            cur = str.find(':');
            string sub_str = str.substr(prev, cur - prev);
            m.insert({sub_str, {}});
            str = str.substr(cur + 1);
            istringstream ss(str);

            while (getline(ss, sbuffer, ','))
                m[sub_str].insert(sbuffer);
            
            if (i == 0)
                f = sub_str;
        }
        cout << dfs(f) << "\n";
        m.clear();
        visit.clear();
    }
    return 0;
}