// BOJ_1946_신입 사원

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    int t;
    int arr[100005];
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n, count = 1;
        cin >> n;

        for (int j = 0; j < n; j++) {
            int a, b;
            cin >> a >> b;
            arr[a - 1] = b;
        }
        for (int k = 1; k < n; k++) {
            int flag = 0;
            for (int l = k - 1; l >= 0; l--) {
                if (arr[k] > arr[l]) {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
                count++;
        }
        cout << count << "\n";
    }

    return 0;
}