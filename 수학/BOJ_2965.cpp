// BOJ_2965_캥거루 세마리

#include <math.h>

#include <iostream>
using namespace std;

int main() {
    int a, b, c, count = 0;
    cin >> a >> b >> c;

    while (1) {
        if (abs(a - b) == 1 && abs(b - c) == 1)
            break;
        if (abs(a - b) > abs(b - c)) {
            count++;
            c = b;
            b = a + 1;
        } else if (abs(a - b) <= abs(b - c)) {
            count++;
            a = b;
            b = c - 1;
        }
    }
    cout << count << '\n';
    return 0;
}