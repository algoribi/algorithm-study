// algorithm_study
// BOJ_1629_곱셈

#include <iostream>

using namespace std;

long long a, b, c;
long long pow(long long num, long long cnt) {
    if (cnt == 0)
        return 1;
    else if (cnt == 1)
        return num;

    if (cnt % 2 == 1)
        return pow(num, cnt - 1) * num;
    else
        return (pow(num, cnt / 2) % c) * (pow(num, cnt / 2) % c) % c;
}

int main() {
    cin >> a >> b >> c;
    cout << pow(a, b) % c;
    return 0;
}