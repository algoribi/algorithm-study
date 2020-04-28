// BOJ_2884_알람 시계

#include <iostream>

using namespace std;

int main() {
    int h, m;
    cin >> h >> m;
    int sum = h * 60 + m - 45;
    if (sum < 0)
        cout << (1440 + sum) / 60 << " " << (1440 + sum) % 60;
    else
        cout << sum / 60 << " " << sum % 60;
    return 0;
}