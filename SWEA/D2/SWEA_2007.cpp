#include <iostream>
#define endl "\n"
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        int counter = 0;
        for (int j = 1; j < s.size(); j++) {
            if (s[counter] == s[j])
                counter++;
            else
                counter = 0;
        }
        cout << "#" << i << " " << s.size() - counter << endl;
    }
    return 0;
}