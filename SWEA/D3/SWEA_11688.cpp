#include <iostream>
#define endl "\n"

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        string s;
        cin >> s;
        int a = 1, b = 1;
        for (int j = 0; j < s.size(); j++) {
            if (s[j] == 'L')
                b = a + b;
            else
                a = a + b;
        }
        cout << "#" << i << " " << a << " " << b << endl;
    }
}