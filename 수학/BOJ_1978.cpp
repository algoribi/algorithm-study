// BOJ_1978_소수 찾기

#include <iostream>

using namespace std;

int main() {
    int n, count = 0, chk = 0;
    int arr[101];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (arr[i] == 1)
            continue;
        for (int j = 2; j < arr[i]; j++) {
            if (arr[i] % j == 0) {
                chk = 1;
                break;
            }
        }
        if (chk == 0)
            count++;
        else
            chk = 0;
    }

    cout << count << '\n';
    return 0;
}