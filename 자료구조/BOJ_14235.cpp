#include <iostream>
#include <set>
#define endl "\n"

using namespace std;

int main() {
    int n, a, b;
    multiset<int, greater<int>> s;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        if (a == 0) {
            if (s.size() == 0)
                cout << -1 << endl;
            else {
                cout << *s.begin() << endl;
                s.erase(s.begin());
            }
        } else {
            for (int j = 0; j < a; j++) {
                cin >> b;
                s.insert(b);
            }
        }
    }

    return 0;
}