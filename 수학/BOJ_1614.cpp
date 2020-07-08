#include <iostream>

using namespace std;

int main() {
    int n, num, fl = 0, hand[5][2] = {{8, 0}, {6, 2}, {4, 4}, {2, 6}, {0, 8}};
    cin >> n >> num;
    long answer = n;
    for (int i = 0; i < num; i++) {
        if (hand[n - 1][fl] == 0)
            num++;
        answer += hand[n - 1][fl];
        if (fl == 0)
            fl = 1;
        else
            fl = 0;
    }
    cout << answer - 1;
    return 0;
}