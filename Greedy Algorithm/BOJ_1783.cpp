// algorithm study
// BOJ_1783_병든 나이트

#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    if (n == 1)
        cout << 1;
    else if (n == 2)
        cout << min(4, (m + 1) / 2);
    else if (n > 2) {
        if (m <= 6)
            cout << min(4, m);
        else
            cout << m - 2;
    }
    return 0;
}