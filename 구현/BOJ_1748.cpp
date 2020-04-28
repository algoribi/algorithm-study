// algorithm study
// BOJ_1748_수 이어 쓰기1

#include <iostream>

using namespace std;

int main() {
    int n, answer = 0, i = 1;
    cin >> n;

    while (i <= n) {
        answer += (n - i + 1);
        i *= 10;
    }

    cout << answer;
    return 0;
}