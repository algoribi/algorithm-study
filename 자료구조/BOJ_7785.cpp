// algorithm study
// BOJ_7785_회사에 있는 사람

#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    set<string, greater<string>> pe;
    for (int i = 0; i < n; i++) {
        string name, t;
        cin >> name >> t;
        if (t == "enter")
            pe.insert(name);
        else
            pe.erase(name);
    }
    set<string>::iterator iter;
    for (iter = pe.begin(); iter != pe.end(); ++iter) {
        cout << *iter << "\n";
    }
    return 0;
}