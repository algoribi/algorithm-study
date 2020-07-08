#include <iostream>

using namespace std;

int main() {
    int n, phone[25], Y = 0, M = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> phone[i];
        Y += (phone[i] / 30 + 1) * 10;
        M += (phone[i] / 60 + 1) * 15;
    }
    if (Y > M)
        cout << "M " << M;
    else if (Y == M)
        cout << "Y M " << Y;
    else
        cout << "Y " << Y;
    return 0;
}