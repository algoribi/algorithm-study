// algorithm_study
// BOJ_1074_Z

#include <math.h>

#include <iostream>

using namespace std;

int main() {
    int n, r, c, answer = 0;
    cin >> n >> r >> c;
    n = pow(2, n);
    r += 1;
    c += 1;
    while (1) {
        n /= 2;
        if (c > 0 && c <= n) {
            if (r > 0 && r <= n) {  //1구역
            } else {                //3구역
                r -= n;
                answer += 2 * (n * n);
            }
        } else {
            if (r > 0 && r <= n) {  //2구역
                c -= n;
                answer += 1 * (n * n);
            } else {  //4구역
                r -= n;
                c -= n;
                answer += 3 * (n * n);
            }
        }
        if (n == 1)
            break;
    }

    cout << answer;
    return 0;
}