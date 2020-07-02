#include <iostream>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int t, num;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> num;
        cout << "#" << i + 1 << " ";
        if (num < 100)
            cout << 0 << "\n";
        else if (num < 1000)
            cout << 1 << "\n";
        else if (num < 10000)
            cout << 2 << "\n";
        else if (num < 100000)
            cout << 3 << "\n";
        else if (num < 1000000)
            cout << 4 << "\n";
        else
            cout << 5 << "\n";
    }
    return 0;
}