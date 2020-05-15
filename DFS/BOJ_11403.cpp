// BOJ_11403_경로 찾기

#include <iostream>
#include <vector>

using namespace std;

int arr[105][105], an[105][105], n, in;

void dfs(int p) {
    for (int i = 0; i < n; i++) {
        int chk = arr[p][i];
        if (chk == 0)
            continue;
        else if (chk == 1 && an[in][i] != 1) {
            an[in][i] = 1;
            dfs(i);
        } else if (an[in][i] == 1)
            continue;
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        in = i;
        dfs(i);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << an[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}