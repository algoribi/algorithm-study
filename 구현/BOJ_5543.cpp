// BOJ_5543_상근날드

#include <iostream>

using namespace std;

int main() {
    int min = 2100, add = 0;
    for (int i = 0; i < 5; i++) {
        int m;
        cin >> m;
        if (i < 3 && m < min)
            min = m;
        else if (i == 3) {
            add = min;
            min = m;
        } else if (i == 4 && min > m)
            min = m;
    }
    cout << add + min - 50;
    return 0;
}