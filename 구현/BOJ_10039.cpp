// BOJ_10039_평균 점수

#include <iostream>

using namespace std;

int main() {
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        int t;
        cin >> t;
        if (t < 40)
            t = 40;
        sum += t;
    }
    cout << sum / 5;
    return 0;
}