#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
    int n, num[30];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    set<int> s;
    for (int i = 0; i < n; i++) {
        vector<int> add;
        for (auto it = s.begin(); it != s.end(); it++) {
            add.push_back(*it + num[i]);
        }
        s.insert(num[i]);
        for (int j = 0; j < add.size(); j++) {
            s.insert(add[j]);
        }
    }
    int counter = 1;
    for (auto it = s.begin(); it != s.end(); it++) {
        if (*it != counter) {
            cout << counter;
            return 0;
        }
        counter++;
    }
    cout << counter;
}