// algorithm study
// BOJ_2033_반올림

#include <iostream>

using namespace std;

int main() {
    int n, count = 0;
    cin >> n;

    while (1) {
        if (n / 10 == 0)
            break;

        count++;
        int a = n % 10;
        n = n / 10;

        if (a >= 5)
            n += 1;
    }

    for (int i = 0; i < count; i++) {
        n *= 10;
    }

    cout << n;
    return 0;
}