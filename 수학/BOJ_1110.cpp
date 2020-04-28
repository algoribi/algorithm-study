// BOJ_1110_더하기 사이클

#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int num = n, count = 0;
    while (1) {
        if (n == num && count != 0)
            break;
        num = ((num / 10) + (num % 10)) % 10 + ((num % 10) * 10);
        count++;
    }
    cout << count;
    return 0;
}