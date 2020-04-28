// algorithm_study
// BOJ_2858_기숙사 바닥

#include <iostream>

using namespace std;

int main() {
    int r, b, l, w;
    cin >> r >> b;

    for (int i = 3; i <= (r + b) / 2; i++) {
        if ((r + b) % i == 0) {
            l = (r + b) / i;
            w = i;
            if ((w - 2) * (l - 2) == b) {
                break;
            }
        }
    }

    cout << l << " " << w;

    return 0;
}