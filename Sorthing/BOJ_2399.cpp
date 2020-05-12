// algorithm study
// BOJ_2399_거리의 합

#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    int n;
    cin >> n;
    long long a[10010], answer = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                answer += a[i];
                answer -= a[j];
            } else {
                answer -= a[i];
                answer += a[j];
            }
        }
    }

    cout << 2 * answer;
    return 0;
}