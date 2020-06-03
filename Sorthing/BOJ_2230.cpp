// algorithm study
// BOJ_2230 수 고르기

#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    int n, m, num[100010], start = 0, end = 1, answer = 2000000001;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    sort(num, num + n);

    while (start < n) {
        if (start == end)
            end++;
        else if (num[end] - num[start] < m)
            end++;
        else if (num[end] - num[start] == m) {
            answer = num[end] - num[start];
            break;
        } else {
            if (answer > num[end] - num[start])
                answer = num[end] - num[start];
            start++;
        }
    }
    cout << answer;
    return 0;
}