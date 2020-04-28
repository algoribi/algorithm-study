// algorithm_study
// BOJ_1459_걷기

#include <iostream>

using namespace std;

int main() {
    long long x, y, w, s, an;
    cin >> x >> y;
    cin >> w >> s;

    if (w * 2 <= s)
        an = (x + y) * w;
    else {
        if (x <= y) {
            an = x * s;
            if ((y - x) * w > (y - x) * s)
                an = an + ((y - x) % 2) * w + ((y - x) - (y - x) % 2) * s;
            else
                an += (y - x) * w;
        } else {
            an = y * s;
            if ((x - y) * w > (x - y) * s)
                an = an + ((x - y) % 2) * w + ((x - y) - (x - y) % 2) * s;
            else
                an += (x - y) * w;
        }
    }

    cout << an;

    return 0;
}