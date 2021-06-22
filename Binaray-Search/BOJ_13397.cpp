#include <iostream>

using namespace std;

int arr[5010];

int main() {
    int n, m, left = 0, right = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (arr[i] > right)
            right = arr[i];
    }

    int ans = right;
    while (left <= right) {
        int mid = (left + right) / 2, counter = 1, min_num = arr[0], max_num = arr[0];

        for (int i = 1; i < n; i++) {
            if (arr[i] > max_num)
                max_num = arr[i];
            else if (arr[i] < min_num)
                min_num = arr[i];

            if (max_num - min_num > mid) {
                max_num = min_num = arr[i];
                counter++;
            }
        }
        if (counter > m)
            left = mid + 1;
        else {
            if (ans > mid)
                ans = mid;
            right = mid - 1;
        }
    }

    cout << ans;


    return 0;
}