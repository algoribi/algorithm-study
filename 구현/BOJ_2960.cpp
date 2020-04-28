// algorithm study
// BOJ_2960_에라토스테네스의 체

#include <iostream>

using namespace std;

int main() {
    int n, k, count = 0, arr[1010] = {0};
    cin >> n >> k;

    for (int i = 2; i <= n; i++) {
        if (arr[i] == 0) {
            int j = 1;
            while (1) {
                if (i * j > n)
                    break;
                if (arr[i * j] == 0) {
                    arr[i * j] = 1;
                    count++;
                }
                if (count == k) {
                    cout << i * j;
                    return 0;
                }
                j++;
            }
        }
    }

    return 0;
}