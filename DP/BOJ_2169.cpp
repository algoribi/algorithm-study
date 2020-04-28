// algorithm study
// BOJ_2169_로봇 조종하기

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int map[1010][1010];
    int left_max[1010][1010];
    int right_max[1010][1010];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        //left_max
        for (int j = 0; j < m; j++) {
            if (i == 0) {
                if (j == 0)
                    left_max[i][j] = map[i][j];
                else
                    left_max[i][j] = map[i][j] + left_max[i][j - 1];
            } else {
                if (j == 0)
                    left_max[i][j] = map[i][j] + map[i - 1][j];
                else {
                    int a = left_max[i][j - 1] + map[i][j];
                    int b = map[i - 1][j] + map[i][j];
                    if (a > b)
                        left_max[i][j] = a;
                    else
                        left_max[i][j] = b;
                }
            }
        }
        //right_max
        for (int j = m - 1; j >= 0; j--) {
            if (i == 0) {
                right_max[i][j] = left_max[i][j];
            } else {
                if (j == m - 1)
                    right_max[i][j] = map[i][j] + map[i - 1][j];
                else {
                    int a = right_max[i][j + 1] + map[i][j];
                    int b = map[i - 1][j] + map[i][j];
                    if (a > b)
                        right_max[i][j] = a;
                    else
                        right_max[i][j] = b;
                }
            }
        }

        for (int j = 0; j < m; j++) {
            if (left_max[i][j] > right_max[i][j])
                map[i][j] = left_max[i][j];
            else
                map[i][j] = right_max[i][j];
        }
    }

    cout << map[n - 1][m - 1];

    return 0;
}