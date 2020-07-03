#include <iostream>

using namespace std;

char arr[55][55];
int n, m, answer = 65;

void cheak(int i, int j, int chk) {
    int counter = 0;
    for (int x = i; x < i + 8; x++) {
        if (counter > answer)
            break;
        for (int y = j; y < j + 8; y++) {
            if (chk == 0 && arr[x][y] != 'W')
                counter++;
            else if (chk == 1 && arr[x][y] != 'B')
                counter++;

            if (chk == 0)
                chk = 1;
            else
                chk = 0;
        }
        if (chk == 0)
            chk = 1;
        else
            chk = 0;
    }
    if (counter < answer)
        answer = counter;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i <= n - 8; i++) {
        for (int j = 0; j <= m - 8; j++) {
            cheak(i, j, 0);
            cheak(i, j, 1);
        }
    }
    cout << answer;
    return 0;
}